/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:59:48 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/09 22:04:26 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
	public:
		// Constructors
		Form();
		Form(const Form &copy);
		Form(const std::string name, bool isSigned, const int signeGrade, const int executeGrade);
		
		// Destructor
		~Form();
		
		// Operators
		Form & operator=(const Form &assign);
		
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

		// member functions
		void	beSigned(const Bureaucrat &n);

	private:

		void	checkGrade(int grade);

		const std::string _name;
		bool _isSigned;
		const int _signeGrade;
		const int _executeGrade;
		
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Form &object);

#endif