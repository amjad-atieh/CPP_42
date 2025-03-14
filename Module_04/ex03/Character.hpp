/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:50:50 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/14 21:28:44 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

# define MAX_MATERIAS 4

class Character : public ICharacter
{
	public:

		// Constructors
		Character();
		Character(const Character &copy);
		
		// Destructor
		~Character();
		
		// Operators
		Character & operator=(const Character &assign);

		//getters / setters
		// AMateria* getMateria(int idx) const;
		// int getMateriasCount() const;

		//Member functions

	private:

		std::string const	name;
		AMateria*			materias[MAX_MATERIAS];
		int					materias_count;
};

#endif