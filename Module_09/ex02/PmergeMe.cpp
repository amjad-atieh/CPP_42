/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:26:42 by aatieh            #+#    #+#             */
/*   Updated: 2025/08/10 14:18:39 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> splitTwo(std::vector<std::vector<int> > &lst, size_t i, size_t j)
{
    std::vector<int> newVec;

    while (lst[i].size() > j)
    {
        newVec.push_back(lst[i][j]);
        lst[i].erase(lst[i].begin() + j);
    }
    return newVec;
}

std::deque<int> splitTwo(std::deque<std::deque<int> > &lst, size_t i, size_t j)
{
    std::deque<int> newVec;

    while (lst[i].size() > j)
    {
        newVec.push_back(lst[i][j]);
        lst[i].erase(lst[i].begin() + j);
    }
    return newVec;
}

void start(const std::vector<int> &input)
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
}

std::deque<std::deque<int> > start(const std::deque<int> &input)
{
    std::deque<std::deque<int> > lst;

    if (input.size() <= 0)
        return lst;
    for (size_t i = 0; i < input.size(); i++)
    {
        std::deque<int> tmp;
        tmp.push_back(input[i]);
        lst.push_back(tmp);
    }
    sortVec(lst);
    return lst;
}

void starting(char **av)
{
    std::vector<int> dataVec;
    std::deque<int> dataDeque;
    std::deque<std::deque<int> > lst;
    clock_t end;
    clock_t begin;
    double timeVec, timeDeque;

    grapInput(av + 1, dataVec);
    grapInput(av + 1, dataDeque);

    std::cout << "Before: ";
    for (size_t i = 0; i < dataVec.size(); i++)
    {
        std::cout << dataVec[i] << " ";
    }
    std::cout << std::endl;
    begin = clock();
    start(dataVec);
    end = clock();
    timeVec = (end - begin) * 1e6 / (double)CLOCKS_PER_SEC;
    begin = clock();
    lst = start(dataDeque);
    end = clock();
    timeDeque = (end - begin) * 1e6 / (double)CLOCKS_PER_SEC;

    std::cout << "After: ";
    for (size_t i = 0; i < lst.size(); i++)
    {
        std::cout << lst[i][0] << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << dataDeque.size() << " elements with std::deque : " << timeDeque << " us" << std::endl;
    std::cout << "Time to process a range of " << dataVec.size() << " elements with std::deque : " << timeVec << " us" << std::endl;
}
