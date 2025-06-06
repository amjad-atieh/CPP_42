/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:14:56 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/16 22:01:57 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <limits.h>
#include <errno.h>

// Constructors
ScalarConverter::ScalarConverter()
{
	std::cout << "\e[0;33mDefault Constructor called of ScalarConverter\e[0m" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of ScalarConverter\e[0m" << std::endl;
}

// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "\e[0;31mDestructor called of ScalarConverter\e[0m" << std::endl;
}

// Operators
ScalarConverter & ScalarConverter::operator=(const ScalarConverter &assign)
{
	(void) assign;
	return *this;
}

// Helper functions
bool safeAtoi(const char* str, int& out) {
    errno = 0;
    char* end;
    long val = std::strtol(str, &end, 10);

    if (errno == ERANGE || val > INT_MAX || val < INT_MIN)
        return false;

    out = static_cast<int>(val);
    return true;
}

static bool allNum(const std::string &input)
{
	size_t	i;
	int	comma;

	i = 0;
	comma = 0;
	if (input.empty())
		return false;
	if (input[i] == '-')
		i++;
	while (i < input.size() && (std::isdigit(input[i]) || input[i] == '.'))
	{
		if (input[i] == '.')
			comma++;
		i++;
	}
	if (comma <= 1 && (i == input.size() || (i == input.size() - 1 && input[i] == 'f')))
		return true;
	else
		return false;
}

static void printChar(const std::string &input)
{
	int	r;
	
	if (input.size() == 1 &&  !std::isdigit(input[0]))
		std::cout << "char: " << input[0] << std::endl;
	else if (allNum(input) == true && safeAtoi(input.c_str(), r))
	{
		if ((r >= 0 && r <= 31 && !std::isspace(r)) || r == 127)
			std::cout << "char: Non displayable" << std::endl;
		else if (r < 0 || r > 255)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: " << static_cast <char>(r) << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
}

static void printInt(const std::string &input)
{
	int	r;
	
	if (allNum(input) == true && safeAtoi(input.c_str(), r))
	{
		std::cout << "int: " << r << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;
}

static bool  pseudoLiteral(const std::string &input)
{
	size_t	i;

	i = 0;
	if (input.size() < 3)
		return false;
	if (input[i] == '-' || input[i] == '+')
		i++;
	if (input.compare(i, 4, "nan") == 0 || input.compare(i, 5, "nanf") == 0
		|| input.compare(i, 4, "inf") == 0 || input.compare(i, 5, "inff") == 0)
		return true;
	else
		return false;
}

static void printFloatDouble(const std::string &input)
{
	double	r;

	if (allNum(input) == true || pseudoLiteral(input) == true)
	{
		r = std::atof(input.c_str());
		if (std::floor(r) != r)
		{
			std::cout << "float: " << static_cast <float>(r) << "f" << std::endl;
			std::cout << "double: " << r << std::endl;
		}
		else
		{
			std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast <float>(r) << "f" << std::endl;
			std::cout << "double: " << r << std::endl;
		}
	}
	else
	{
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

// Memeber function
void ScalarConverter::convert(const std::string &input)
{
	printChar(input);
	printInt(input);
	printFloatDouble(input);
}
