#include "BitcoinExchange.hpp"
#include <climits>
#include <cstdlib>
#include <cstring>

// Constructors
BitcoinExchange::BitcoinExchange()
{
    std::cout << "\e[0;33mDefault Constructor called of BitcoinExchange\e[0m" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    (void)copy;
    std::cout << "\e[0;33mCopy Constructor called of BitcoinExchange\e[0m" << std::endl;
}

// Destructor
BitcoinExchange::~BitcoinExchange()
{
    std::cout << "\e[0;31mDestructor called of BitcoinExchange\e[0m" << std::endl;
}

// Operators
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &assign)
{
    (void)assign;
    return *this;
}

// Memebr functions
time_t validateDate(int year, int month, int day)
{
    struct tm t;
    time_t time;

    t.tm_year = year;
    t.tm_mon = month;
    t.tm_mday = day;
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 0;
    t.tm_isdst = -1;

    time = mktime(&t);

    if (time == -1)
        return false;

    if (!(t.tm_year == year && t.tm_mon == month && t.tm_mday == day))
        throw(BitcoinExchange::BadDate());
    return (time);
}

bool safeAtoi(const char *str, int &out)
{
    errno = 0;
    char *end;
    long val;

    val = std::strtol(str, &end, 10);

    if (errno == ERANGE || val > INT_MAX || val < INT_MIN || *end != '\0')
    {
        return false;
    }

    out = static_cast<int>(val);
    return true;
}

static time_t takeDate(std::string date)
{
    struct tm dateTime;
    time_t timeStamp;
    std::string tmp;
    std::string rest;

    tmp = date.substr(0, date.find_first_of("-"));
    rest = date.substr(date.find_first_of("-") + 1);
    if (!safeAtoi(tmp.c_str(), dateTime.tm_year))
        throw(BitcoinExchange::BadDate());
    dateTime.tm_year -= 1900;

    tmp = rest.substr(0, rest.find_first_of("-"));
    rest = rest.substr(rest.find_first_of("-") + 1);
    if (!safeAtoi(tmp.c_str(), dateTime.tm_mon))
        throw(BitcoinExchange::BadDate());
    dateTime.tm_mon -= 1;

    tmp = rest.substr(0, rest.find_first_of("-"));
    rest = rest.substr(rest.find_first_of("-") + 1);
    if (!safeAtoi(tmp.c_str(), dateTime.tm_mday))
        throw(BitcoinExchange::BadDate());

    timeStamp = validateDate(dateTime.tm_year, dateTime.tm_mon, dateTime.tm_mday);
    return (timeStamp);
}

void BitcoinExchange::addDataLine(std::string &line)
{
    std::string numString;
    std::string dateString;
    time_t date;
    float num;
    char *end;

    numString = line.substr(line.find(",") + 1);
    dateString = line.substr(0, line.find(","));
    date = takeDate(dateString);
    num = strtof(numString.c_str(), &end);
    _data.insert(std::pair<time_t, float>(date, num));
}

void BitcoinExchange::addData(const char *dataFile)
{
    std::string line;
    std::ifstream file(dataFile);

    if (!file.is_open())
    {
        throw FailedToOpenFile();
    }

    std::getline(file, line);

    while (std::getline(file, line))
    {
        addDataLine(line);
    }
}

void BitcoinExchange::takeLine(std::stringstream &line)
{
    char *end;
    std::string dateString;
    std::string tmp;
    std::string numString;
    time_t date;
    float num;

    line >> dateString;
    line >> tmp;
    if (strcmp("|", tmp.c_str()))
        throw(BitcoinExchange::BadInput());
    line >> numString;
    date = takeDate(dateString);
    num = strtof(numString.c_str(), &end);
    if (num < 0)
        throw(BitcoinExchange::NegativeNumber());
    else if (num > 1000)
        throw(BitcoinExchange::NumberTooLarge());
    std::map<time_t, float>::iterator it = _data.upper_bound(date);
    if (it != _data.begin())
    {
        --it;
        std::cout << dateString << " => " << numString << " = " << num * it->second << std::endl;
    }
    else
    {
        std::cout << "No earlier date found." << std::endl;
    }
}

void BitcoinExchange::takeInput(const char *inputFile)
{
    std::string line;
    std::ifstream file(inputFile);

    if (!file.is_open())
    {
        throw FailedToOpenFile();
    }

    std::getline(file, line);

    while (std::getline(file, line))
    {
        try
        {
            std::stringstream formattedLine(line);
            takeLine(formattedLine);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

// Exceptions
const char *BitcoinExchange::FailedToOpenFile::what() const throw()
{
    return "unable to open file";
}

const char *BitcoinExchange::BadInput::what() const throw()
{
    return "format is invalid";
}

const char *BitcoinExchange::BadDate::what() const throw()
{
    return "date is invalid";
}

const char *BitcoinExchange::NegativeNumber::what() const throw()
{
    return "negative numbers are not accepted";
}

const char *BitcoinExchange::NumberTooLarge::what() const throw()
{
    return "numbers above 1000 are not accepted";
}
