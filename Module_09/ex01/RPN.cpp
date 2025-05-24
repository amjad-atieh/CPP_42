/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:26:12 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/24 23:55:47 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Helper fcuntions
static bool	isOperation(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}

// Constructors
RPN::RPN()
{
}

RPN::RPN(const RPN &copy)
{
	(void) copy;
}

// Destructor
RPN::~RPN()
{
}

// Member functions
int	RPN::doMath(char *input)
{
	_num = std::stack<int>();
	int tmp;

	for (int i = 0; input[i]; i++)
	{
		if (std::isdigit(input[i]))
			_num.push(input[i] - '0');
		else if (std::isspace(input[i]))
			continue;
		else if (isOperation(input[i]))
		{
			if (_num.size() < 2)
				throw RPN::InvalidFormat();
			tmp = _num.top();
			_num.pop();
			if (input[i] == '+')
				_num.top() += tmp;
			else if (input[i] == '-')
				_num.top() -= tmp;
			else if (input[i] == '*')
				_num.top() *= tmp;
			else if (input[i] == '/')
				_num.top() /= tmp;
		}
		else
			throw RPN::InvalidChar();
	}
	return _num.top();
}

// Operators
RPN & RPN::operator=(const RPN &assign)
{
	(void) assign;
	return *this;
}

// Exceptions
const char * RPN::InvalidChar::what() const throw()
{
	return "Invalid charecter found";
}

const char * RPN::InvalidFormat::what() const throw()
{
	return "Invalid format";
}
