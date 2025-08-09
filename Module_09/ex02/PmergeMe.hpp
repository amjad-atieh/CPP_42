/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:26:48 by aatieh            #+#    #+#             */
/*   Updated: 2025/08/09 22:08:16 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include <vector>

extern int counter;

template <typename T, typename F>
struct myPair {
  T first;
  F second;
};

// void splitVec(std::vector<int>& input, std::vector<int>& newA, std::vector<int>& newB);
// std::vector<int> sortVec(std::vector<int>& a, std::vector<int>& b, std::vector<int>* oldB);
// std::vector<int>& start(std::vector<int>& input);

void start(const std::vector<int>& input);

class PmergeMe
{
  public:
    // Constructors
    PmergeMe();
    PmergeMe(const PmergeMe &copy);
    // PmergeMe(char **input);

    // Destructor
    ~PmergeMe();

    // Getters
    // const std::vector<int>	&getVector() const;

    // Operators
    PmergeMe &operator=(const PmergeMe &assign);

    // Member functions
    std::vector<int> &sort(std::vector<int> &res);

  private:
    std::vector<myPair<int, int> > _pairs;
    std::vector<int> _res;
};

#endif