#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
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