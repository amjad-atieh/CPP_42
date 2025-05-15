/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:13:06 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/15 16:13:07 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include <fstream>
# include <iostream>

class ShrubberyCreationForm : public AForm
{
	public:
		// Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm(const std::string target);

		// Destructor
		~ShrubberyCreationForm();

		// Getters
		std::string	getTarget() const;

		// Operators
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &assign);

		// Exceptions
		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};

		// member functions
		void	execute(Bureaucrat const & executor) const;

	private:
		std::string const _target;
};

#endif