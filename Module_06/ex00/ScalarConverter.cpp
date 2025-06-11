/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:14:56 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/10 16:10:28 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
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

    if ((errno == ERANGE || val > INT_MAX || val < INT_MIN)
		&& (*end == '\0' || (*end == 'f' && *(end + 1) == '\0')))
	{
        return false;
	}

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
	else if (allNum(input) && safeAtoi(input.c_str(), r))
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
	
	if (allNum(input) && safeAtoi(input.c_str(), r))
	{
		std::cout << "int: " << r << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;
}

static int count_decimal_digits(const std::string& input)
{
	size_t	len;
    std::string::size_type dot_pos = input.find('.');
    if (dot_pos == std::string::npos)
	{
        return 0;
	}
	len = input.length() - 1;
	while (input.at(len) == '0' && len > dot_pos)
	{
		len--;
	}
    // Count digits after the dot
    return len - dot_pos;
}

static void printFloatDouble(const std::string &input)
{
	double	r;
	float	f;
	char	*end;
	int		digits;

	f = strtof(input.c_str(), &end);
	if (*end == '\0' || (*end == 'f' && *(end + 1) == '\0'))
	{
		digits = count_decimal_digits(input);
		r = strtod(input.c_str(), &end);
		if (digits > 0)
		{
			std::cout << "float: " << std::fixed
				<< std::setprecision(digits + 1)
				<< f << "f" << std::endl;
			std::cout << "double: " << std::fixed
				<< std::setprecision(digits)
				<< r << std::endl;
		}
		else
		{
			std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
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
