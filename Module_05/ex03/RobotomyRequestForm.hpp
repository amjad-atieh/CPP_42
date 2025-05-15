/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:13:02 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/15 16:13:03 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include <cstdlib>
# include <ctime>
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
	public:

		// Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm(const std::string &target);

		// Destructor
		~RobotomyRequestForm();

		// Operators
		RobotomyRequestForm & operator=(const RobotomyRequestForm &assign);

		// Getters
		std::string	getTarget() const;
		// member functions
		void	execute(Bureaucrat const & executor) const;

	private:
		std::string const _target;
};

#endif