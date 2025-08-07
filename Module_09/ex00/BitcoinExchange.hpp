#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <ios>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange
{
  public:
    // Constructors
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copy);

    // Destructor
    ~BitcoinExchange();

    // Operators
    BitcoinExchange &operator=(const BitcoinExchange &assign);

    // Memeber functions
    void addDataLine(std::string &line);
    void addData(const char *dataFile);
    void takeInput(const char *inputFile);
    void takeLine(std::stringstream &line);

    // Getters
    const std::map<time_t, float>& getData() const;

    class FailedToOpenFile : public std::exception
    {
        virtual const char *what() const throw();
    };
    class BadInput : public std::exception
    {
        virtual const char *what() const throw();
    };
    class BadDate : public std::exception
    {
        virtual const char *what() const throw();
    };
    class NegativeNumber : public std::exception
    {
        virtual const char *what() const throw();
    };
    class NumberTooLarge : public std::exception
    {
        virtual const char *what() const throw();
    };

  private:
    std::map<time_t, float> _data;
};

#endif