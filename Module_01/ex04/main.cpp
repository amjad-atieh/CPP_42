/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:26:49 by aatieh            #+#    #+#             */
/*   Updated: 2025/01/20 13:25:56 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void	ft_replace(std::string &line, std::string replace, std::string replacement, int index)
{
	line.erase(index, replace.length());
	line.insert(index, replacement);
}

bool	open_files(char *argv[], std::ifstream	&in_file, std::ofstream	&out_file)
{
	std::string replace_name;

	in_file.open(argv[1], std::fstream::in);
	if (!in_file.is_open())
	{
		std::cout << "Unable to open " << argv[1] << std::endl;
		return false;
	}
	replace_name = argv[1] + (std::string)".replace";
	out_file.open(replace_name.c_str(), std::ios::out);
	if (!out_file.is_open())
	{
		in_file.close();
		std::cout << "Unable to open or create " << replace_name << std::endl;
		return false;
	}
	return true;
}

int	main(int argc, char **argv)
{
	std::ifstream	in_file;
	std::ofstream	out_file;
	std::string		line;
	int				index;

	if (argc != 4)
	{
		std::cout << "incorrect number of inputs\n";
		return 1;
	}
	if (!open_files(argv, in_file, out_file))
		return 2;
	while (std::getline(in_file, line))
	{
		index = line.find(argv[2]);
		if (index != -1)
			ft_replace(line, argv[2], argv[3], index);
		out_file << line << std::endl;
	}
	in_file.close();
	out_file.close();
	return 0;
}
