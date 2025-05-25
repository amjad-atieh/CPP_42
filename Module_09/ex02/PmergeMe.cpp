/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:26:42 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/25 15:39:24 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructors
PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	(void) copy;
}

// Destructor
PmergeMe::~PmergeMe()
{
}

// Operators
PmergeMe & PmergeMe::operator=(const PmergeMe &assign)
{
	(void) assign;
	return *this;
}

// Helper functions
static bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
    return a.second < b.second;
}

static void	fillPairs(std::vector<int> &seq, std::vector<std::pair<int, int> > &pairs)
{
	int	first;
	int	second;

	for (size_t i = 0; i < seq.size(); i += 2)
	{
		if (i + 1 < seq.size())
		{
			// If there's a pair, sort it
			first = seq[i];
			second = seq[i + 1];
			if (first > second) std::swap(first, second);
			pairs.push_back(std::make_pair(first, second));
		}
		else
		{
			// If there's an odd element, treat it as a pair with the second element as infinity
			pairs.push_back(std::make_pair(seq[i], seq[i]));
		}
	}
}

static void insertion(std::vector<int> &res, std::vector<int> &smallerElements)
{
	int	left, right, b, mid;

	for (std::vector<int>::const_iterator it = smallerElements.begin(); it != smallerElements.end(); ++it) {
		b = *it;
		left = 0;
		right = res.size();
		while (left < right)
		{
			mid = left + (right - left) / 2;
			if (res[mid] < b)
				left = mid + 1;
			else
				right = mid;
		}
		res.insert(res.begin() + left, b);
	}
}

// Member function
std::vector<int>	&PmergeMe::sort(std::vector<int> &seq)
{
	_res = std::vector<int>();
	fillPairs(seq, _pairs);

	std::sort(_pairs.begin(), _pairs.end(), comparePairs);

	for (std::vector<std::pair<int, int> >::iterator p = _pairs.begin(); p != _pairs.end(); ++p)
	{
		_res.push_back(p->second);
	}

	std::vector<int> smallerElements;
	for (std::vector<std::pair<int, int> >::iterator p = _pairs.begin(); p != _pairs.end(); ++p)
	{
		smallerElements.push_back(p->first);
	}

	insertion(_res, smallerElements);

	_pairs = std::vector<std::pair<int, int> >();
	return _res;
}
