/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:42:20 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/27 20:30:33 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
					Weapon( std::string weapon_type );
					~Weapon();
		std::string	getType() const;
		void		setType( std::string weapon_name );

	private:
		std::string type;
};


#endif
