/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:13:04 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/15 16:13:05 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137), _target("defualt")
{
	std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy.getName(), 145, 137), _target(copy.getTarget())
{
	std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreation", 145, 137), _target(target)
{
	std::cout << "\e[0;33mVariable Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\e[0;31mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

// Getters
std::string	ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void drawAsciiTrees(std::ofstream& file) {
    if (!file.is_open()) {
        return;
    }

    file << "               v .   ._, |_  .,\n";
    file << "            `-._\\/  .  \\ /    |/_\n";
    file << "                \\\\  _\\, y | \\\\//\n";
    file << "          _\\_.___\\\\, \\\\/ -.\\||\n";
    file << "            `7-,--.`._||  / / ,\n";
    file << "            /'     `-. `./ / |/_.'\n";
    file << "                      |    |//\n";
    file << "                      |_    /\n";
    file << "                      |-   |\n";
    file << "                      |   =|\n";
    file << "                      |    |\n";
    file << "--------------------/ ,  . \\--------._\n";
}

// member functions
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	out_file;
	std::string		file_name;

	this->excutableCheck(executor);
	file_name = _target;
	file_name += "_shrubbery";
	out_file.open(file_name.c_str(), std::ios::out);
	drawAsciiTrees(out_file);
	if (out_file.is_open())
	{
		std::cout << "Shrubbery created in " << file_name << std::endl;
		out_file.close();
	}
	else
	{
		std::cerr << "Failed to create shrubbery in " << file_name << std::endl;
	}
}

// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	(void)assign;
	return *this;
}

