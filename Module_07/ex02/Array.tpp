/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:57:19 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/22 19:17:37 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

template <typename T>
class Array
{
	public:
		// Constructors
		Array(){
			_size = 0;
			_array = new T[_size];
		};
		Array(const Array &copy){
			_array = new T[0];
			*this = copy;
		};
		Array(const unsigned int n){
			_size = n;
			_array = new T[_size];
		};

		// Destructor
		~Array(){
			delete[] _array; // Free the allocated memory
		};
		
		// Operators
		Array & operator=(const Array &assign){
			if (this != &assign)
			{
				delete[] _array; // Free the existing memory
				_size = assign.size(); // Copy the size
				_array = new T[_size]; // Allocate new memory for the array
				for (unsigned int i = 0; i < _size; ++i)
					_array[i] = assign[i]; // Copy the elements
			}
			return *this;
		};
		T & operator[](unsigned int i) const{
			if (i >= _size)
				throw std::out_of_range("Index out of range");
			return _array[i];
		};

		// Getters
		unsigned int	size() const{
			return _size;
		};

	private:
		T				*_array;
		unsigned int	_size;
};
