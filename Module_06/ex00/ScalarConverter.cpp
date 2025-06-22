/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:14:56 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/22 19:57:24 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
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

bool ScalarConverter::safeAtoi(const char* str, int& out)
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

bool	ScalarConverter::printChar(const std::string &input)
{
	char	c;

	if (input.size() == 1 && !isdigit(input[0]))
	{
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

// Memeber function
bool	ScalarConverter::printInt(const std::string &input)
{
	int	i;

	if (safeAtoi(input.c_str(), i))
	{
		printOneChar(i);
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed <<  std::setprecision(1) << static_cast<float> (i) << 'f' << std::endl;
		std::cout << "double: " << static_cast<double> (i) << std::endl;
		return true;
	}
	return	false;
}

bool	ScalarConverter::printDouble(const std::string &input)
{
	int		digits;
	char	*end;
	double	d;

	digits = count_decimal_digits(input);
	d = strtod(input.c_str(), &end);
	if (*end == '\0')
	{
		printOneChar(d);
		printOneInt(d);
		std::cout << "float: " << std::fixed  << std::setprecision(digits) << static_cast<float> (d) << 'f' << std::endl;
		std::cout << "double: " << d << std::endl;
		return	true;
	}
	return false;
}

bool	ScalarConverter::printFloat(const std::string &input)
{
	int		digits;
	char	*end;
	float	f;

	digits = count_decimal_digits(input);
	f = strtof(input.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0')
	{
		printOneChar(f);
		printOneInt(f);
		std::cout << "float: " << std::fixed << std::setprecision(digits) << f << 'f' << std::endl;
		std::cout << "double: " << static_cast<double> (f) << std::endl;
		return true;
	}
	return false;
}

void	ScalarConverter::impossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

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
