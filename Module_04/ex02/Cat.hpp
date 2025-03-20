/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:16:28 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/20 15:36:59 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public: 
		// Constructors
		Cat();
		Cat(const Cat &copy);

		// Destructor
		~Cat();

		// Operators
		Cat & operator=(const Cat &assign);

		//getters / setters
		Brain	*getBrain() const;
		void	setBrain(Brain assgin);

		// Member functions
		void		setIdea(int index, std::string idea);
		std::string	getIdea(int index) const;

	private:

		Brain *brain;
};

#endif