/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:37:28 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/23 16:58:27 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>

// Constructors
Span::Span()
{
	_N = 100;
	_isSorted = false;
}

Span::Span(const Span &copy)
{
	*this = copy;
	_isSorted = false;
}

Span::Span(const unsigned N)
{
	_N = N;
	_isSorted = false;
}

// Destructor
Span::~Span()
{
}

// Operators
Span & Span::operator=(const Span &assign)
{
	_N = assign.getN();
	_content = assign.getContent();
	return *this;
}

// Getters
const unsigned int	&Span::getN() const
{
	return _N;
}

const std::vector<int>	&Span::getContent() const
{
	return _content;
}

// Member functions
void	Span::addNumber(const int num)
{
	if (_content.size() >= _N)
		throw Span::FullStorage();
	_content.push_back(num);
	_isSorted = false;
}

int	Span::shortestSpan()
{
	int	res = INT_MAX;

	if (_content.size() <= 1)
		throw Span::NoSpan();
	if (_isSorted == false)
	{
		std::sort(_content.begin(), _content.end());
		_isSorted = true;
	}
	for (size_t i = 0; i + 1 < _content.size(); i++)
	{
		if (res > _content.at(i + 1) - _content.at(i))
			res = _content.at(i + 1) - _content.at(i);
	}
	return res;
}

int	Span::longestSpan()
{
	int	res;

	if (_content.size() <= 1)
		throw Span::NoSpan();
	if (_isSorted == false)
	{
		std::sort(_content.begin(), _content.end());
		_isSorted = true;
	}
	res = _content.at(_content.size() - 1) - _content.at(0);
	return res;
}

// Exceptions
const char *Span::FullStorage::what() const throw()
{
	return "Storage is already full";
}

const char	*Span::NoSpan::what() const throw()
{
	return "Storage doesn't have enough elemnts to have a span";
}
