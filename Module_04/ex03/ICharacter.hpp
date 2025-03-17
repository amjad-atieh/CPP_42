/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:51:55 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/17 19:43:16 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>

class AMateria;

class ICharacter
{
	public:
		virtual	~ICharacter() {}
		virtual	std::string const & getName() const = 0;
		virtual	void equip(AMateria* m) = 0;
		virtual	void unequip(int idx) = 0;
		virtual	void use(int idx, ICharacter& target) = 0;
};

#endif
