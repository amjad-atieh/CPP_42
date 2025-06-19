/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:57:46 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/19 19:31:02 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <string>
# include <stdint.h>
# include "Data.hpp"


class Serialization
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t &raw);

	private:
		// Constructors
		Serialization();
		Serialization(const Serialization &copy);
		
		// Destructor
		~Serialization();
		
		// Operators
		Serialization & operator=(const Serialization &assign);
		
		
};

#endif