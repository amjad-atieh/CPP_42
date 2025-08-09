/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:26:42 by aatieh            #+#    #+#             */
/*   Updated: 2025/08/09 22:16:23 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int counter = 0;

// Constructors
PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    (void)copy;
}

// Destructor
PmergeMe::~PmergeMe()
{
}

// Operators
PmergeMe &PmergeMe::operator=(const PmergeMe &assign)
{
    (void)assign;
    return *this;
}

// Helper functions
static bool comparePairs(const myPair<int, int> &a, const myPair<int, int> &b)
{
    return a.second < b.second;
}

static void fillPairs(std::vector<int> &seq, std::vector<myPair<int, int> > &pairs)
{
    int first;
    int second;
    myPair<int, int> tmpPair;

    for (size_t i = 0; i < seq.size(); i += 2)
    {
        if (i + 1 < seq.size())
        {
            // If there's a pair, sort it
            first = seq[i];
            second = seq[i + 1];
            if (first > second)
                std::swap(first, second);
            tmpPair.first = first;
            tmpPair.second = second;
            pairs.push_back(tmpPair);
        }
        else
        {
            // If there's an odd element, treat it as a pair with the second element as infinity
            tmpPair.first = seq[i];
            tmpPair.second = seq[i];
            pairs.push_back(tmpPair);
        }
    }
}

static void insertion(std::vector<int> &res, std::vector<int> &smallerElements)
{
    int left, right, b, mid;

    for (std::vector<int>::const_iterator it = smallerElements.begin(); it != smallerElements.end(); ++it)
    {
        b = *it;
        left = 0;
        right = res.size();
        while (left < right)
        {
            counter++;
            mid = left + (right - left) / 2;
            if (res[mid] < b)
                left = mid + 1;
            else
                right = mid;
        }
        res.insert(res.begin() + left, b);
    }
}

// static void newInsertion(std::vector<int> &a, std::vector<int> &b, std::vector<int> *oldB)
// {
//     int left, right, current, mid, tmp, index = 0;

//     for (std::vector<int>::const_iterator it = b.begin(); it != b.end(); ++it)
//     {
//         current = *it;
//         left = 0;
//         right = a.size();
//         while (left < right)
//         {
//             counter++;
//             mid = left + (right - left) / 2;
//             if (a[mid] < current)
//                 left = mid + 1;
//             else
//                 right = mid;
//         }
//         a.insert(a.begin() + left, current);
//         std::cout << left << std::endl;
//         // tmp = (*oldB)[index];
//         // (*oldB)[index] = (*oldB)[left];
//         // (*oldB)[left] = tmp;
//         (void)tmp;
//         (void)oldB;
//         index++;
//     }
// }

// Member function
std::vector<int> &PmergeMe::sort(std::vector<int> &seq)
{
    _res = std::vector<int>();
    fillPairs(seq, _pairs);

    std::sort(_pairs.begin(), _pairs.end(), comparePairs);

    for (std::vector<myPair<int, int> >::iterator p = _pairs.begin(); p != _pairs.end(); ++p)
    {
        _res.push_back(p->second);
    }

    std::vector<int> smallerElements;
    for (std::vector<myPair<int, int> >::iterator p = _pairs.begin(); p != _pairs.end(); ++p)
    {
        smallerElements.push_back(p->first);
    }

    insertion(_res, smallerElements);

    _pairs = std::vector<myPair<int, int> >();
    return _res;
}

// void splitVec(std::vector<int>& input, std::vector<int>& newA, std::vector<int>& newB)
// {
//     size_t i;

//     for (i = 0; i + 1 < input.size(); i += 2)
//     {
//         counter++;
//         if (input[i] > input[i + 1])
//         {
//             newA.push_back(input[i]);
//             newB.push_back(input[i + 1]);
//         }
//         else
//         {
//             newA.push_back(input[i + 1]);
//             newB.push_back(input[i]);
//         }
//     }
//     if (i < input.size())
//         newB.push_back(input[i]);
// }

// std::vector<int> sortVec(std::vector<int>& a, std::vector<int>& b, std::vector<int>* oldB = NULL)
// {
//   if (a.size() > 1)
//   {
//     std::vector<int> newA, newB;
//     splitVec(a, newA, newB);
//     a = sortVec(newA, newB, &b);
//   }
//   newInsertion(a, b, oldB);
//   return a;
// }


// std::vector<int>& start(std::vector<int>& input)
// {
//   std::vector<int> newA, newB;

//   splitVec(input, newA, newB);
//   input = sortVec(newA, newB);
//   return input;
// }

std::vector<int> splitTwo(std::vector<std::vector<int> >& lst, size_t i, size_t j)
{
  std::vector<int> newVec;

  while (lst[i].size() > j)
  {
    newVec.push_back(lst[i][j]);
    lst[i].erase(lst[i].begin() + j);
  }
  return newVec;
}

void megreTwo(std::vector<std::vector<int> >& lst, size_t i, size_t j)
{
  std::vector<int>& a = lst[i], b = lst[j];
  if (a.size() == 0)
  {
    lst.erase(lst.begin() + i);
  }
  else if (b.size() == 0)
  {
    lst.erase(lst.begin() + j);
  }
  else if (a[0] > b[0])
  {
    while (b.size())
    {
      a.push_back(b[0]);
      b.erase(b.begin());
    }
    lst.erase(lst.begin() + j);
  }
  else
  {
    while (a.size())
    {
      b.push_back(a[0]);
      a.erase(a.begin());
    }
    lst.erase(lst.begin() + i);
  }
}

void insertSort(std::vector<std::vector<int> >& lst)
{
  size_t initalSize = lst[0].size();
  size_t j;
  int left, right, b, mid;

  for (size_t i = 0; i < lst.size(); i++)
  {
    if (lst[i].size() == initalSize)
    {
      j = (lst[i].size() / 2) + (lst[i].size() % 2);
      b = lst[i][j];
      left = i + 1;
      right = lst.size();
      while (left < right)
      {
          counter++;
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

void sortVec(std::vector<std::vector<int> >& lst)
{
  for (size_t i = 0; i + 1 < lst.size(); i++)
  {
    megreTwo(lst, i, i + 1);
  }
  while (lst[0].size() > 1)
  {
    insertSort(lst);
  }
}

void start(const std::vector<int>& input)
{
  std::vector<std::vector<int> > lst;

  if (input.size() <= 0)
    return;
  for (size_t i = 0; i < input.size(); i++)
  {
    std::vector<int> tmp;
    tmp.push_back(input[i]);
    lst.push_back(tmp);
  }
  sortVec(lst);
  for (size_t i = 0; i < lst.size(); i++)
  {
    std::cout << lst[i][0] << " ";
  }
  std::cout << std::endl;
}
