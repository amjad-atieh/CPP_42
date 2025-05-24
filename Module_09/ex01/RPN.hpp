/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:26:14 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/24 23:51:43 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string> 
# include <stack>
# include <cstring>

class RPN
{
	public:
		// Constructors
		RPN();
		RPN(const RPN &copy);

		// Destructor
		~RPN();

		// Operators
		RPN & operator=(const RPN &assign);

		// Member functions
		int	doMath(char *input);

		// Exceptions
		class InvalidChar : public std::exception
		{
			const char * what() const throw();	
		};
		class InvalidFormat : public std::exception
		{
			const char * what() const throw();	
		};

	private:
		std::stack<int>		_num;
		// std::stack<char>	_op;
};

#endif