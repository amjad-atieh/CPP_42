/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:13:26 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/29 14:35:45 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

#include <stdexcept>

template <typename T> class Array
{
  public:
    Array();
    Array(const Array &copy);
    Array(const unsigned int n);
    ~Array();

    Array &operator=(const Array &assign);
    const T &operator[](unsigned int i) const;
    T &operator[](unsigned int i);
    unsigned int size() const;

  private:
    T *_array;
    unsigned int _size;
};

#include "Array.tpp"

#endif