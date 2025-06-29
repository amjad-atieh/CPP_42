/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:30:32 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/29 17:02:01 by aatieh           ###   ########.fr       */
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
		typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

		// Constructors
		MutantStack();
		MutantStack(const MutantStack &copy);

		// Destructor
		~MutantStack();

		// Member functions
		iterator begin();
		const const_iterator cbegin() const;
		iterator end();
		const const_iterator cend() const;

		reverse_iterator rbegin();
		const const_reverse_iterator crbegin() const;
		reverse_iterator rend();
		const const_reverse_iterator crend() const;

		// Operators
		MutantStack & operator=(const MutantStack &assign);
};

# include "MutantStack.tpp"

#endif
