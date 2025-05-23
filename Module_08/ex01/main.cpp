/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:36:21 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/23 16:47:27 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "Span.hpp"  // Adjust if the header name is different

int main() {
	try {
		std::cout << "==== Basic Span Test ====" << std::endl;
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n==== Span Overflow Test ====" << std::endl;
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);  // Should throw
	}
	catch (std::exception &e) {
		std::cerr << "Expected exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n==== Not Enough Numbers Test ====" << std::endl;
		Span sp(10);
		sp.addNumber(5);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;  // Should throw
	}
	catch (std::exception &e) {
		std::cerr << "Expected exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n==== Insert Range Test ====" << std::endl;
		Span sp(100);
		std::vector<int> vec;
		for (int i = 0; i < 50; ++i)
			vec.push_back(i * 2);
		sp.insert(vec.begin(), vec.end());
		std::cout << "Shortest Span (should be 2): " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n==== Random Large Range Test ====" << std::endl;
		Span sp(10000);
		std::srand(std::time(NULL));
		for (int i = 0; i < 10000; ++i)
			sp.addNumber(std::rand());
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
