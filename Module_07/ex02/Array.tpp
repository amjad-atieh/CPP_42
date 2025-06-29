/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:57:19 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/29 14:36:18 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>
# include <string>
#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	_size = 0;
	_array = new T[_size]();
}

template <typename T>
Array<T>::Array(const Array &copy)
{
	_array = new T[0];
	*this = copy;
}

template <typename T>
Array<T>::Array(const unsigned int n)
{
	_size = n;
	_array = new T[_size]();
}

// Destructor
template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}
		
// Operators
template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &assign)
{
	if (this != &assign)
	{
		delete[] _array;
		_size = assign.size();
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_array[i] = assign[i];
	}
	return *this;
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw std::out_of_range("Index out of range");
	return _array[i];
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::out_of_range("Index out of range");
	return _array[i];
}

// Getters
template <typename T>
unsigned int	Array<T>::size() const
{
	return _size;
}

#endif
