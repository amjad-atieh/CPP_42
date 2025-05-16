/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:59:46 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/16 17:25:27 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors
Form::Form() : _name("cog"), _signeGrade(75), _executeGrade(75)
{
	_isSigned = false;
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const Form &copy) : _name(copy.getName()), _signeGrade(copy.getSigneGrade()), _executeGrade(copy.getExecuteGrade())
{
	_isSigned = copy.getSigned();
	checkGrade(_signeGrade);
	checkGrade(_executeGrade);
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const std::string name, const int signeGrade, const int executeGrade) : _name(name), _signeGrade(signeGrade), _executeGrade(executeGrade)
{
	_isSigned = false;
	checkGrade(_signeGrade);
	checkGrade(_executeGrade);
	std::cout << "\e[0;33mFields Constructor called of Form\e[0m" << std::endl;
}

// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}

// Operators
Form & Form::operator=(const Form &assign)
{
	_isSigned = assign.getSigned();
	return *this;
}

// Getters
std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _isSigned;
}

int Form::getSigneGrade() const
{
	return _signeGrade;
}

int Form::getExecuteGrade() const
{
	return _executeGrade;
}

// Exceptions
const char * Form::GradeTooHighException::what() const throw()
{
	return "grade higher than possible";
}

const char * Form::FormAlreadySigned::what() const throw()
{
	return "Signed form cannot be signed again";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "grade lower than possible";
}

void	Form::beSigned(const Bureaucrat &n)
{
	if (_isSigned)
		throw Form::FormAlreadySigned();
	else if (n.getGrade() <= _signeGrade)
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

void	Form::checkGrade(const int grade) const
{
	if (grade > 150)
		throw Form::GradeTooLowException();
	else if (grade < 1)
		throw Form::GradeTooHighException();
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const Form &object)
{
	stream << "the " << object.getName() << " form was not signed yet and the grade you need to sign it is at lease " << object.getSigneGrade() << " and you need to be at least grade " << object.getExecuteGrade() << " to execute it" << std::endl;
	return stream;
}

