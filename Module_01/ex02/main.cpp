/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:49:52 by aatieh            #+#    #+#             */
/*   Updated: 2025/01/20 07:41:48 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string string;
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	string = "HI THIS IS BRAIN";
	std::cout << "The memory address of the string variable is: "
		<< &string << std::endl;
	std::cout << "The memory address held by stringPTR is: "
		<< &stringPTR << std::endl;
	std::cout << "The memory address held by stringREF is: "
		<< &stringREF << std::endl << std::endl;
	std::cout << "The value of the string variable: "
		<< string << std::endl;
	std::cout << "The value pointed to by stringPTR: "
		<< *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: "
		<< stringREF << std::endl;
	return 0;
}
