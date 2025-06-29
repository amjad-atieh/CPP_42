/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:30:32 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/29 17:19:04 by aatieh           ###   ########.fr       */
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
const typename std::deque<T>::const_iterator MutantStack<T>::cbegin() const
{
	return (this->c.cbegin());
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
const typename std::deque<T>::const_iterator MutantStack<T>::cend() const
{
	return (this->c.cend());
}


template <typename T>
typename std::deque<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T>
const typename std::deque<T>::const_reverse_iterator MutantStack<T>::crbegin() const
{
	return (this->c.crbegin());
}

template <typename T>
typename std::deque<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}

template <typename T>
const typename std::deque<T>::const_reverse_iterator MutantStack<T>::crend() const
{
	return (this->c.crend());
}

// Operators
template <typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack<T> &assign)
{
	std::stack<T>::operator=(assign);
	return *this;
}

#endif
