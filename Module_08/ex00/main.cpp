/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:46:13 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/22 21:31:38 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>       // Note: This won't work directly unless you test keys or values specifically
#include <algorithm>

int main()
{
	// Vector test
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i)
		vec.push_back(i);
	std::cout << "Vector: " << easyfind(vec, 5) << " (should be 1)\n";
	std::cout << "Vector: " << easyfind(vec, 20) << " (should be 0)\n";

	// List test
	std::list<int> lst;
	lst.push_back(42);
	lst.push_back(24);
	std::cout << "List: " << easyfind(lst, 42) << " (should be 1)\n";
	std::cout << "List: " << easyfind(lst, 0) << " (should be 0)\n";

	// Deque test
	std::deque<int> deq;
	deq.push_back(1);
	deq.push_back(2);
	deq.push_back(3);
	std::cout << "Deque: " << easyfind(deq, 3) << " (should be 1)\n";

	// Set test
	std::set<int> s;
	s.insert(10);
	s.insert(20);
	std::cout << "Set: " << easyfind(s, 10) << " (should be 1)\n";
	std::cout << "Set: " << easyfind(s, 30) << " (should be 0)\n";

	// Empty container test
	std::vector<int> empty;
	std::cout << "Empty Vector: " << easyfind(empty, 1) << " (should be 0)\n";

	// Negative numbers
	std::vector<int> negatives;
	negatives.push_back(-5);
	negatives.push_back(-10);
	std::cout << "Negative Vector: " << easyfind(negatives, -10) << " (should be 1)\n";
	std::cout << "Negative Vector: " << easyfind(negatives, 0) << " (should be 0)\n";

	// Duplicate elements
	std::vector<int> duplicates(5, 7); // 7 7 7 7 7
	std::cout << "Duplicates: " << easyfind(duplicates, 7) << " (should be 1)\n";

	// Testing first and last elements
	std::vector<int> bounds;
	bounds.push_back(100);
	bounds.push_back(200);
	bounds.push_back(300);
	std::cout << "First Element: " << easyfind(bounds, 100) << " (should be 1)\n";
	std::cout << "Last Element: " << easyfind(bounds, 300) << " (should be 1)\n";

	// Large input test
	std::vector<int> large;
	for (int i = 0; i < 10000; ++i)
		large.push_back(i);
	std::cout << "Large Vector (find 9999): " << easyfind(large, 9999) << " (should be 1)\n";
	std::cout << "Large Vector (not found): " << easyfind(large, 10001) << " (should be 0)\n";

	return 0;
}

