/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:16:34 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/20 20:46:42 by aatieh           ###   ########.fr       */
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

		// Member functions
		void		setIdea(int index, std::string idea);
		std::string	getIdea(int index) const;
		void		makeSound() const;

	private:

		Brain *brain;
};

#endif