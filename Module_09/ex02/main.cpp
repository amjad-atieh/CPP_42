/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:25:39 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/23 19:41:33 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Error: incorret format\n"
			<<"The correct format is ./PmergeMe arg1 arg2 ..." << std::endl;
		return 1;
	}
	return 0;
}
