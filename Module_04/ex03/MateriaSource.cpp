/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 06:18:33 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/14 21:22:20 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructors
MateriaSource::MateriaSource()
{
	std::cout << "\e[0;33mDefault Constructor called of MateriaSource\e[0m" << std::endl;
	for(int i = 0; i < MAX_MATERIAS; i++)
		materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of MateriaSource\e[0m" << std::endl;
}

// Destructor
MateriaSource::~MateriaSource()
{
	std::cout << "\e[0;31mDestructor called of MateriaSource\e[0m" << std::endl;
}

// Operators
MateriaSource & MateriaSource::operator=(const MateriaSource &assign)
{
	(void) assign;
	return *this;
}

// Member Functions  
void	MateriaSource::learnMateria(AMateria* m)
{
	int	i;
	for(i = 0; i < MAX_MATERIAS; i++)
		if (this->materia[i] == NULL)
			break;
	if (i < MAX_MATERIAS)
		this->materia[i] = m;
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	int	i;

	for(i = 0; i < MAX_MATERIAS; i++)
		if (this->materia[i] != NULL && this->materia[i]->getType() == type)
			return (this->materia[i]->clone());
	return 0;
}
