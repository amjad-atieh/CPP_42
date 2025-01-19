/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:07:24 by aatieh            #+#    #+#             */
/*   Updated: 2025/01/13 19:49:50 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	j;

	for (int i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j]; j++)
			std::cout << (char)std::toupper(argv[i][j]);
		if (argv[i][--j] != ' ' && (i + 1 < argc && argv[i + 1][0] != ' '))
			std::cout << " ";
	}
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
