/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 06:18:33 by aatieh            #+#    #+#             */
/*   Updated: 2025/04/21 18:46:10 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructors
MateriaSource::MateriaSource()
{
	for(int i = 0; i < MAX_MATERIAS; i++)
		materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	*this = copy;
}

// Destructor
MateriaSource::~MateriaSource()
{
	for(int i = 0; i < MAX_MATERIAS; i++)
		if (materia[i])
			delete materia[i];
}

// Operators
MateriaSource & MateriaSource::operator=(const MateriaSource &assign)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (materia[i])
			delete materia[i];
		if (assign.materia[i])
			materia[i] = assign.materia[i]->clone();
		else
			materia[i] = NULL;
	}
	return *this;
}

// Member Functions  
void	MateriaSource::learnMateria(AMateria* m)
{
	int	i;

	i = 0;
	while(i < MAX_MATERIAS && materia[i])
		i++;
	if (i < MAX_MATERIAS)
		materia[i] = m->clone();
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < MAX_MATERIAS; i++)
		if (this->materia[i] != NULL && this->materia[i]->getType() == type)
			return (this->materia[i]->clone());
	return 0;
}
