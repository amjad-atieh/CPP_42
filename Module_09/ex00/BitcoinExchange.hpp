/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:25:31 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/24 20:32:24 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <ctime>

class BitcoinExchange
{
	public:
		// Constructors
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);

		// Destructor
		~BitcoinExchange();

		// Operators
		BitcoinExchange & operator=(const BitcoinExchange &assign);

		// Getters
		const std::map<time_t, float> &getData() const;

		// Member function
		void	addData(const std::string &newDate);
		void	readFile(const char *fileName);
		static time_t StringToTimeT(const std::string& dateStr);
		float	dateValue(const std::string &queryDate) const;

		// Exceptions
		class IncorrectFormat : public std::exception
		{
			virtual const char *what() const throw();	
		};
		class IncorrectValue : public std::exception
		{
			virtual const char *what() const throw();	
		};

	private:
		std::map<time_t, float> _data;
};

#endif