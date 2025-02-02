/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:28:12 by aatieh            #+#    #+#             */
/*   Updated: 2025/01/21 19:39:12 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define NUMOFLEVELS 4

class Harl
{
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
	typedef void (Harl::*HarlMemFn)();
	struct s_LevelFn
	{
		std::string level;
		HarlMemFn function;
	};
	struct s_LevelFn functions[4];
public:
	Harl();
	~Harl();
	void	complain( std::string level );
};

#endif
