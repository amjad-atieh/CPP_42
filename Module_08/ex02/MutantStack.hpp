/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:30:32 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/29 14:42:56 by aatieh           ###   ########.fr       */
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
		const iterator begin() const;
		iterator end();
		const iterator end() const;

		// Operators
		MutantStack & operator=(const MutantStack &assign);
};

# include "MutantStack.tpp"

#endif
