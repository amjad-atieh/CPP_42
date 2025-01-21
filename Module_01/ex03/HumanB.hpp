/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:44:16 by aatieh            #+#    #+#             */
/*   Updated: 2025/01/20 09:05:48 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string	name;
	Weapon		*weapon;
public:
	HumanB( std::string	name );
	~HumanB();
	void	attack();
	void	setWeapon( Weapon &weapon );
};

#endif
