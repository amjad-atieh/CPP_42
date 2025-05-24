/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:26:12 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/23 19:26:12 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Constructors
RPN::RPN()
{
	std::cout << "\e[0;33mDefault Constructor called of RPN\e[0m" << std::endl;
}

RPN::RPN(const RPN &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of RPN\e[0m" << std::endl;
}


// Destructor
RPN::~RPN()
{
	std::cout << "\e[0;31mDestructor called of RPN\e[0m" << std::endl;
}


// Operators
RPN & RPN::operator=(const RPN &assign)
{
	(void) assign;
	return *this;
}

