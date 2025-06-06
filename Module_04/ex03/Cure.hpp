/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:41:05 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/22 19:30:23 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		// Constructors
		Cure();
		Cure(const Cure &copy);

		// Destructor
		~Cure();

		// Operators
		Cure & operator=(const Cure &assign);

		// Member functions
		AMateria* clone() const;
		void use(ICharacter& target);

};

#endif
