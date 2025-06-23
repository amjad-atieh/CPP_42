/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:36:21 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/23 17:28:50 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    try
    {
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
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n==== Span Overflow Test ====" << std::endl;
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
    }
    catch (std::exception &e)
    {
        std::cerr << "Expected exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n==== Not Enough Numbers Test ====" << std::endl;
        Span sp(10);
        sp.addNumber(5);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Should throw
    }
    catch (std::exception &e)
    {
        std::cerr << "Expected exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n==== Insert Range Test ====" << std::endl;
        Span sp(100);
        std::vector<int> vec;
        for (int i = 0; i < 50; ++i)
            vec.push_back(i * 2);
        sp.insert(vec.begin(), vec.end());
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n==== Random Large Range Test ====" << std::endl;
        Span sp(20000);
        for (int i = 0; i < 10000; ++i)
            sp.addNumber(-i * 3);
        for (int i = 0; i < 10000; ++i)
            sp.addNumber(i * 3);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
