/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:03:18 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/11 17:55:21 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat a;
	Bureaucrat b("idiot", 130);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	b.incrementGrade();
	Bureaucrat c(b);
	std::cout << c << std::endl;
	try
	{
		a.decrementGrade();
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	Bureaucrat d("nerd", 1);
	try
	{
		b.decrementGrade();
		d.decrementGrade();
		d.incrementGrade();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		d.decrementGrade();
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << d << std::endl;
	std::cout << b << std::endl;
	return 0;
}
