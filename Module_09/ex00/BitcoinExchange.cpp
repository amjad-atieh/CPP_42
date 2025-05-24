/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:25:28 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/24 21:51:08 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdio>
#include <fstream>
#include <cstdlib>

// Constructors
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

// Destructor
BitcoinExchange::~BitcoinExchange()
{
}

// Operators
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	_data = assign.getData();
	return *this;
}

// Getters
const std::map<time_t, float> &BitcoinExchange::getData() const
{
	return _data;
}

// Helper functions
static float	extractValue(const std::string &newDate)
{
	std::string	valueString;
	size_t		numPos;
	float		value;
	char		*endPtr;

	numPos = newDate.find('|');
	if (numPos == std::string::npos || numPos + 1 >= newDate.size())
	{
		throw BitcoinExchange::IncorrectFormat();
	}
	valueString  = newDate.substr(numPos + 1);
	value = std::strtod(valueString.c_str(), &endPtr);
	if (*endPtr != '\0')
	{
		throw BitcoinExchange::IncorrectFormat();
	}
	return value;
}

// Member functions
void	BitcoinExchange::addData(const std::string &newDate)
{
	float		value;
	time_t	formattedDate;
	
	value = extractValue(newDate);
	if (value > 1000 || value < 0)
	{
		throw BitcoinExchange::IncorrectValue();
	}
	formattedDate = StringToTimeT(newDate);
	if (formattedDate == -1)
	{
		throw BitcoinExchange::IncorrectFormat();
	}
	_data[formattedDate] = value;
}

void	BitcoinExchange::readFile(const char *fileName)
{
	std::ifstream	file(fileName);
	std::string		line;

	while (std::getline(file, line))
		addData(line);
	std::cout << "The file: " << fileName << " was added successfully" << std::endl;
	file.close();
}

time_t BitcoinExchange::StringToTimeT(const std::string& dateStr)
{
	struct tm t = {};

	if (sscanf(dateStr.c_str(), "%d-%d-%d", &t.tm_year, &t.tm_mon, &t.tm_mday) != 3)
		return -1;
	t.tm_year -= 1900;
	t.tm_mon -= 1;

	struct tm t_check = t;
	time_t result = mktime(&t);
	struct tm* normalized = localtime(&result);

	if (normalized->tm_year != t_check.tm_year ||
		normalized->tm_mon  != t_check.tm_mon  ||
		normalized->tm_mday != t_check.tm_mday)
	{
		throw BitcoinExchange::IncorrectFormat();
	}
	return result;
}

float	BitcoinExchange::dateValue(const std::string &queryDate) const
{
	time_t formattedDate = StringToTimeT(queryDate);
	if (formattedDate == -1)
	{
		std::cerr << "Error: incorrect format entered\n";
		return -1;
	}

	std::map<time_t, float>::const_iterator it = _data.lower_bound(formattedDate);

	if (it != _data.end() && it->first == formattedDate)
		return it->second;
	else if (it != _data.begin())
	{
		--it;
		return it->second;
	}
	else
	{
		std::cerr << "Error: No date in database is earlier than or equal to "
			<< queryDate << std::endl;
		return -1;
	}
}

// Exceptions
const char *BitcoinExchange::IncorrectFormat::what() const throw()
{
	return "Date Format incorrect";
}

const char *BitcoinExchange::IncorrectValue::what() const throw()
{
	return "Value is outside of acceptable range";
}
