/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:30:32 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/29 14:43:25 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

// Constructors
template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) : std::stack<T>(copy)
{
}


// Destructor
template <typename T>
MutantStack<T>::~MutantStack()
{
}


// Member functions
template <typename T>
typename std::deque<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
const typename std::deque<T>::iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
const typename std::deque<T>::iterator MutantStack<T>::end() const
{
	return (this->c.end());
}

// Operators
template <typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack<T> &assign)
{
	std::stack<T>::operator=(assign);
	return *this;
}

#endif
