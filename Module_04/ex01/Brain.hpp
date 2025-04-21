/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:57:00 by aatieh            #+#    #+#             */
/*   Updated: 2025/04/21 18:00:35 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define IDEAS_NUM 100

class Brain
{
	public:
		// Constructors
		Brain();
		Brain(const Brain &copy);
		
		// Destructor
		~Brain();
		
		// Operators
		Brain & operator=(const Brain &assign);

		//getters / setters
		std::string getIdea(int index) const;
		void setIdeas(const std::string *ideas);
		void setIdea(int index, std::string idea);

	private:

		std::string ideas[IDEAS_NUM];
};

#endif