/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:13:26 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/15 16:13:31 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
	public:
		// Constructors
		AForm();
		AForm(const AForm &copy);
		AForm(const std::string name, const int signeGrade, const int executeGrade);
		
		// Destructor
		virtual ~AForm();
		
		// Operators
		AForm & operator=(const AForm &assign);
		
		// Getters
		std::string getName() const;
		bool getSigned() const;
		int getSigneGrade() const;
		int getExecuteGrade() const;

		// Exceptions
		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};
		class FormUnsigned : public std::exception {
			virtual const char* what() const throw();
		};

		// member functions
		void			beSigned(const Bureaucrat &n);
		virtual void	execute(Bureaucrat const & executor) const = 0;
	
	protected:

		void	excutableCheck(Bureaucrat const & executor) const;

	private:

		void	checkGrade(const int grade) const;

		const std::string _name;
		bool _isSigned;
		const int _signeGrade;
		const int _executeGrade;
		
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const AForm &object);

#endif