/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:42:20 by aatieh            #+#    #+#             */
/*   Updated: 2025/01/20 09:00:26 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string type;
public:
	Weapon( std::string weapon_type );
	~Weapon();
	std::string	getType() const;
	void		setType( std::string weapon_name );
};


#endif
