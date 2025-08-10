/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:25:39 by aatieh            #+#    #+#             */
/*   Updated: 2025/08/10 14:07:47 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// void grapInput(char **input, std::vector<int> &data)
// {
//     char *endptr;
//     long value;

//     errno = 0;
//     for (size_t i = 0; input[i] != NULL; i++)
//     {
//         value = std::strtol(input[i], &endptr, 10);
//         if (*endptr != '\0')
//         {
//             throw std::invalid_argument("Invalid input: not a valid integer");
//         }
//         if (errno == ERANGE || value > INT_MAX || value < INT_MIN)
//         {
//             throw std::out_of_range("Input value out of range for int");
//         }
//         if (value < 0)
//         {
//             throw std::invalid_argument("Negative numbers are not allowed");
//         }
//         data.push_back(static_cast<int>(value));
//     }
// }

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cerr << "Error: incorret format\n"
                  << "The correct format is ./PmergeMe arg1 arg2 ..." << std::endl;
        return 1;
    }
    try
    {
        starting(av);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}
