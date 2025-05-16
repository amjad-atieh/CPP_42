/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:13:17 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/16 17:35:29 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
AForm::AForm() : _name("cog"), _signeGrade(75), _executeGrade(75)
{
	_isSigned = false;
	std::cout << "\e[0;33mDefault Constructor called of AForm\e[0m" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy.getName()), _signeGrade(copy.getSigneGrade()), _executeGrade(copy.getExecuteGrade())
{
	_isSigned = copy.getSigned();
	checkGrade(_signeGrade);
	checkGrade(_executeGrade);
	std::cout << "\e[0;33mCopy Constructor called of AForm\e[0m" << std::endl;
}

AForm::AForm(const std::string name, const int signeGrade, const int executeGrade) : _name(name), _signeGrade(signeGrade), _executeGrade(executeGrade)
{
	_isSigned = false;
	checkGrade(_signeGrade);
	checkGrade(_executeGrade);
	std::cout << "\e[0;33mFields Constructor called of AForm\e[0m" << std::endl;
}

// Destructor
AForm::~AForm()
{
	std::cout << "\e[0;31mDestructor called of AForm\e[0m" << std::endl;
}

// Operators
AForm & AForm::operator=(const AForm &assign)
{
	_isSigned = assign.getSigned();
	return *this;
}

// Getters
std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _isSigned;
}

int AForm::getSigneGrade() const
{
	return _signeGrade;
}

int AForm::getExecuteGrade() const
{
	return _executeGrade;
}

// Exceptions
const char * AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

const char * AForm::FormAlreadySigned::what() const throw()
{
	return "Signed form cannot be signed again";
}

const char * AForm::FormUnsigned::what() const throw()
{
	return "unasgined forms cannot be excuted";
}

// member functions
void	AForm::beSigned(const Bureaucrat &n)
{
	if (_isSigned)
		throw AForm::FormAlreadySigned();
	else if (n.getGrade() <= _signeGrade)
		_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::checkGrade(const int grade) const
{
	if (grade > 150)
		throw AForm::GradeTooLowException();
	else if (grade < 1)
		throw AForm::GradeTooHighException();
}

void	AForm::excutableCheck(Bureaucrat const & executor) const
{
	if (!_isSigned)
		throw AForm::FormUnsigned();
	else if (executor.getGrade() > _executeGrade)
		throw AForm::GradeTooLowException();
}

// Stream operators
std::ostream & operator<<(std::ostream &stream, const AForm &object)
{
	stream << "the " << object.getName() << " form was not signed yet and the grade you need to sign it is at lease " << object.getSigneGrade() << " and you need to be at least grade " << object.getExecuteGrade() << " to execute it" << std::endl;
	return stream;
}

