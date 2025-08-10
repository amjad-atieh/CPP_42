/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:26:48 by aatieh            #+#    #+#             */
/*   Updated: 2025/08/10 14:07:29 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <climits>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cerrno>
#include <stdexcept>
#include <ctime>

std::vector<int> splitTwo(std::vector<std::vector<int> >& lst, size_t i, size_t j);
std::deque<int> splitTwo(std::deque<std::deque<int> >& lst, size_t i, size_t j);
void start(const std::vector<int>& input);
std::deque<std::deque<int> > start(const std::deque<int>& input);
void starting(char **av);


template <typename Container>
void grapInput(char **input, Container &data)
{
    char *endptr;
    long value;

    errno = 0;
    for (size_t i = 0; input[i] != NULL; i++)
    {
        value = std::strtol(input[i], &endptr, 10);
        if (*endptr != '\0')
        {
            throw std::invalid_argument("Invalid input: not a valid integer");
        }
        if (errno == ERANGE || value > INT_MAX || value < INT_MIN)
        {
            throw std::out_of_range("Input value out of range for int");
        }
        if (value < 0)
        {
            throw std::invalid_argument("Negative numbers are not allowed");
        }
        data.push_back(static_cast<int>(value));
    }
}

template <typename Container>
void megreTwo(Container& lst, size_t i, size_t j)
{
  if (lst[i].size() == 0)
  {
    lst.erase(lst.begin() + i);
  }
  else if (lst[j].size() == 0)
  {
    lst.erase(lst.begin() + j);
  }
  else if (lst[i][0] < lst[j][0])
  {
    while (lst[j].size())
    {
      lst[i].push_back(lst[j][0]);
      lst[j].erase(lst[j].begin());
    }
    lst.erase(lst.begin() + j);
  }
  else
  {
    while (lst[i].size())
    {
      lst[j].push_back(lst[i][0]);
      lst[i].erase(lst[i].begin());
    }
    lst.erase(lst.begin() + i);
  }
}

template <typename Container>
void insertSort(Container& lst, Container& leftOver)
{
  size_t initalSize = lst[0].size();
  size_t j;
  int left, right, b, mid;

  if (leftOver.size() >= 1 && leftOver[0].size() >= initalSize)
  {
    b = leftOver[0][0];
    left = 0;
    right = lst.size();
    while (left < right)
    {
  
        mid = left + (right - left) / 2;
        if (lst[mid][0] < b)
            left = mid + 1;
        else
            right = mid;
    }
    lst.insert(lst.begin() + left, leftOver[0]);
    leftOver.erase(leftOver.begin());
  }
  for (size_t i = 0; i < lst.size(); i++)
  {
    if (lst[i].size() >= initalSize)
    {
      j = (lst[i].size() / 2);
      b = lst[i][j];
      left = i + 1;
      right = lst.size();
      while (left < right)
      {
    
          mid = left + (right - left) / 2;
          if (lst[mid][0] < b)
              left = mid + 1;
          else
              right = mid;
      }
      lst.insert(lst.begin() + left, splitTwo(lst, i, j));
    }
  }
}


template <typename Container>
void sortVec(Container& lst)
{
  Container leftOver;

  while (lst.size() > 1)
  {
    for (size_t i = 0; i + 1 < lst.size(); i++)
    {
      megreTwo(lst, i, i + 1);
      if (i + 2 == lst.size())
      {
        leftOver.insert(leftOver.begin(), lst[i + 1]);
        lst.erase(lst.begin() + i + 1);
      }
    }
  }
  while (lst[0].size() > 1)
  {
    insertSort(lst, leftOver);
  }
}

#endif