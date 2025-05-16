/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:03:14 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/16 17:23:43 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() : name("cog")
{
	grade = 150;
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string init_name, int init_grade) : name(init_name)
{
	setGrade(init_grade);
	std::cout << "\e[0;33mVariable Constructor called of Bureaucrat\e[0m" << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}


// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	setGrade(assign.grade);
	return *this;
}

//getters / setters
std::string	Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::setGrade(int new_grade)
{
	if (new_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (new_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	grade = new_grade;
}

void	Bureaucrat::incrementGrade()
{
	setGrade(grade - 1);
}

void	Bureaucrat::decrementGrade()
{
	setGrade(grade + 1);
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << name << " couldn’t sign " << form.getName()
			<< " becouse his grade is to low!" << std::endl;
		return ;
	}
	catch(const Form::FormAlreadySigned& e)
	{
		std::cerr << name << " couldn’t sign " << form.getName()
			<< " becouse it was already signed" << std::endl;
		return ;
	}
	std::cout << name << " signed " << form.getName() << std::endl;
}

// Exceptions
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object)
{
	stream << object.getName() << ", bureaucrat grade " << object.getGrade();
	return stream;
}
