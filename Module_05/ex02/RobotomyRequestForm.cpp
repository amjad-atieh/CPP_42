#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "\e[0;33mDefault Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy.getName(), 72, 45), _target(copy.getTarget())
{
	std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "\e[0;33mVariable Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[0;31mDestructor called of RobotomyRequestForm\e[0m" << std::endl;
}

// Getters
std::string	RobotomyRequestForm::getTarget() const
{
	return _target;
}

// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	(void) assign;
	return *this;
}

// member functions
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->excutableCheck(executor);
	if (std::rand() % 2 == 0)
		std::cout << _target << "has been robotomized" << std::endl;
	else
		std::cout << _target << "'s robotomy failed." << std::endl;
}

