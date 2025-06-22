/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:14:54 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/22 19:58:56 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits.h>
# include <cmath>

class ScalarConverter
{
	private:
		// Constructors
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);

		// Destructor
		~ScalarConverter();

		// Operators
		ScalarConverter & operator=(const ScalarConverter &assign);

		// Helper functions
		static bool safeAtoi(const char* str, int& out);

		// Member functions
		template <typename T>
		static void	printOneChar(const T &in)
		{
			if (isnan(in) || in < 0 || (in >= 0 && in <= 31 && !std::isspace(in)) || in >= 127)
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: " << static_cast<char> (in) << std::endl;
		};

		template <typename T>
		static void	printOneInt(const T &in)
		{
			if (isnan(in) || in > INT_MAX || in < INT_MIN)
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int> (in) << std::endl;
		};

		static bool	printFloat(const std::string &input);
		static void	impossible();
		static bool	printDouble(const std::string &input);
		static bool	printInt(const std::string &input);
		static bool	printChar(const std::string &input);

	public:
		// Memeber function
		static void convert(const std::string &input);

};

#endif