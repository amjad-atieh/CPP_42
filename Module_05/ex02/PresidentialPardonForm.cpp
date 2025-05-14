#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("defualt")
{
	std::cout << "\e[0;33mDefault Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy.getName(), 25, 5), _target(copy.getTarget())
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "\e[0;33mVariable Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\e[0;31mDestructor called of PresidentialPardonForm\e[0m" << std::endl;
}

// Getters
std::string	PresidentialPardonForm::getTarget() const
{
	return _target;
}

// Operators
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	(void) assign;
	return *this;
}

// member functions
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->excutableCheck(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
