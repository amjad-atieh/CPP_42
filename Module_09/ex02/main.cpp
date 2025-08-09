/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:25:39 by aatieh            #+#    #+#             */
/*   Updated: 2025/08/09 22:08:35 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cerrno>
#include <stdexcept>

void grapInput(char **input, std::vector<int> &data)
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

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cerr << "Error: incorret format\n"
                  << "The correct format is ./PmergeMe arg1 arg2 ..." << std::endl;
        return 1;
    }
    PmergeMe a;

    std::vector<int> data;
    try
    {
        grapInput(av + 1, data);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    // std::vector<int> &res = a.sort(data);
    start(data);
    // for (std::vector<int>::iterator it = data.begin(); it != data.end(); ++it)
    //     std::cout << *it << " ";
    // std::cout << std::endl;
    std::cout << counter << std::endl;
    return 0;
}
