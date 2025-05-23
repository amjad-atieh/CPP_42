/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:30:32 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/23 19:08:51 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
	public:
		typedef typename std::deque<T>::iterator iterator;

		// Constructors
		MutantStack();
		MutantStack(const MutantStack &copy);

		// Destructor
		~MutantStack();

		// Member functions
		iterator begin();
		iterator end();

		// Operators
		MutantStack & operator=(const MutantStack &assign);
};

# include "MutantStack.tpp"

#endif
