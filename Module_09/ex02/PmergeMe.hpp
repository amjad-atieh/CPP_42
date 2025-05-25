/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:26:48 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/25 15:39:33 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <cstdlib>
# include <climits>
# include <algorithm>

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
		PmergeMe & operator=(const PmergeMe &assign);

		// Member functions
		std::vector<int>	&sort(std::vector<int> &res);
		
	private:
		std::vector<std::pair<int, int> >	_pairs;
		std::vector<int>					_res;
};

#endif