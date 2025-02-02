/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:49:52 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/02 17:35:52 by aatieh           ###   ########.fr       */
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
		<< &string << '\n';
	std::cout << "The memory address held by stringPTR is: "
		<< &stringPTR << '\n';
	std::cout << "The memory address held by stringREF is: "
		<< &stringREF << '\n' << '\n';
	std::cout << "The value of the string variable: "
		<< string << '\n';
	std::cout << "The value pointed to by stringPTR: "
		<< *stringPTR << '\n';
	std::cout << "The value pointed to by stringREF: "
		<< stringREF << '\n';
	return 0;
}
