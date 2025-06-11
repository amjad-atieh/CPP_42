/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:14:56 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/11 20:01:39 by aatieh           ###   ########.fr       */
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
static void	printOneChar(char c)
{
	if ((c >= 0 && c <= 31 && !std::isspace(c)) || c == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
}
static bool safeAtoi(const char* str, int& out)
{
    errno = 0;
    char* end;
    long val = std::strtol(str, &end, 10);

    if (errno == ERANGE || val > INT_MAX || val < INT_MIN || *end != '\0')
	{
        return false;
	}

    out = static_cast<int>(val);
    return true;
}

static int count_decimal_digits(const std::string& input)
{
	size_t	len;
    std::string::size_type dot_pos = input.find('.');
    if (dot_pos == std::string::npos)
	{
        return 1;
	}
	len = input.length() - 1;
	if (input[len] == 'f')
		len--;
	while (input[len] == '0' && len > dot_pos)
	{
		len--;
	}
	if (len - dot_pos > 0)
    	return len - dot_pos;
	else
		return 1;
}

static bool printChar(const std::string &input)
{
	char	c;

	if (input.size() == 1 && !isdigit(input[0]))
	{
		std::cout << "From: " <<  "char" << std::endl;
		c = input[0];
		printOneChar(c);
		std::cout << "int: " << static_cast<int> (c) << std::endl;
		std::cout << "float: " << std::fixed <<  std::setprecision(1) << static_cast<float> (c) << 'f' << std::endl;
		std::cout << "double: " << static_cast<double> (c) << std::endl;
		return	true;
	}
	else
		return	false;
}

static bool printInt(const std::string &input)
{
	int	i;

	if (safeAtoi(input.c_str(), i))
	{
		std::cout << "From: " <<  "int" << std::endl;
		printOneChar(static_cast<char> (i));
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed <<  std::setprecision(1) << static_cast<float> (i) << 'f' << std::endl;
		std::cout << "double: " << static_cast<double> (i) << std::endl;
		return true;
	}
	return	false;
}

static bool	printDouble(const std::string &input)
{
	int		digits;
	char	*end;
	double	d;

	digits = count_decimal_digits(input);
	d = strtod(input.c_str(), &end);
	if (*end == '\0')
	{
		std::cout << "From: " <<  "double" << std::endl;
		printOneChar(static_cast<char> (d));
		std::cout << "int: " << static_cast<int> (d) << std::endl;
		std::cout << "float: " << std::fixed  << std::setprecision(digits) << static_cast<float> (d) << 'f' << std::endl;
		std::cout << "double: " << d << std::endl;
		return	true;
	}
	return false;
}

static bool	printFloat(const std::string &input)
{
	int		digits;
	char	*end;
	float	f;

	digits = count_decimal_digits(input);
	f = strtof(input.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0')
	{
		std::cout << "From: " <<  "float" << std::endl;
		printOneChar(static_cast<char> (f));
		std::cout << "int: " << static_cast<int> (f) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(digits) << f << 'f' << std::endl;
		std::cout << "double: " << static_cast<double> (f) << std::endl;
		return true;
	}
	return false;
}

static void	impossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

// Memeber function
void ScalarConverter::convert(const std::string &input)
{
	if (input.size() == 0)
	{
		impossible();
	}
	else if (printChar(input) || printInt(input) || printDouble(input) || printFloat(input))
	{
		return;
	}
	else
	{
		impossible();
	}
}
