/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:07:24 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/02 17:31:04 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
	{
		std::string str = argv[i];
		for (size_t j = 0; j < str.length(); j++)
		{
			if (!isupper(str[j]))
				str.replace(j, 1, 1, toupper(str[j]));
		}
		std::cout << str;
	}
	std::cout << '\n';
	return 0;
}
