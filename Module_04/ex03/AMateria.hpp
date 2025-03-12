/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:25:35 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/12 06:35:29 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
	protected:

		std::string const &type;

	public:

		// Constructors
		AMateria();
		AMateria(const AMateria &copy);
		AMateria(std::string const & type);

		// Destructor
		~AMateria();

		// Operators
		AMateria & operator=(const AMateria &assign);

		// Getters
		std::string const &getType() const;

		// Member functions
		virtual			AMateria* clone() const = 0;
		virtual void	use(ICharacter& target);

};

#endif