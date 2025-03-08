/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:16:34 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/08 09:51:26 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		// Constructors
		Dog();
		Dog(const Dog &copy);
		
		// Destructor
		~Dog();
		
		// Operators
		Dog & operator=(const Dog &assign);

		//getters / setters
		Brain	*getBrain() const;
		void	setBrain(Brain assgin);

	private:

		Brain *brain;
};

#endif