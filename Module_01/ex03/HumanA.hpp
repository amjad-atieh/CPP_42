/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:43:32 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/27 20:30:04 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	public:
				HumanA(std::string name, Weapon &weapon);
				~HumanA();
		void	attack();

	private:
		std::string	name;
		Weapon		&weapon;
};

#endif
