#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:

		// Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm(const std::string &target);

		// Destructor
		~PresidentialPardonForm();

		// Operators
		PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);

		// Getters
		std::string getTarget() const;

		// member functions
		void	execute(Bureaucrat const & executor) const;

	private:
		std::string const _target;
};

#endif