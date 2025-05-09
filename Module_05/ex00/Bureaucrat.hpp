/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:59:50 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/09 21:41:48 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	public:

		// Constructors
		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(std::string init_name, int init_grade);

		// Destructor
		~Bureaucrat();

		// Operators
		Bureaucrat & operator=(const Bureaucrat &assign);

		//getters / setters
		std::string	getName() const;
		int			getGrade() const;

		
		// Member functions
		void				incrementGrade();
		void				decrementGrade();

		// exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		void				setGrade(int new_grade);
		const std::string	name;
		int					grade;
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object);

#endif