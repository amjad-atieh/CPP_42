/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:03:18 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/09 18:20:50 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat a;
	Bureaucrat b("idiot", 130);

	std::cout << a.getName() << "'s grade" << a.getGrade() << std::endl;
	std::cout << b.getName() << "'s grade" << b.getGrade() << std::endl;
	b.incrementGrade();
	Bureaucrat c(b);
	std::cout << c.getName() << "'s grade" << c.getGrade() << std::endl;
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
		d.incrementGrade();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
