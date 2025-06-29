/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:05:04 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/29 18:59:23 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
    std::cout << "===== Basic Stack Behavior =====" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl; // 17
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl; // 1

    std::cout << "\n===== Pushing More Elements =====" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "All elements (using iterator):" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\n===== Copy Constructor (std::stack) =====" << std::endl;
    std::stack<int> s(mstack);
    std::cout << "Copied stack top: " << s.top() << std::endl;

    std::cout << "\n===== Reverse Iteration =====" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << "\n===== Constant Iterators =====" << std::endl;
    MutantStack<int>::iterator cit = mstack.begin();
    while (cit != mstack.end())
    {
        std::cout << *cit << std::endl;
        ++cit;
    }

    std::cout << "\n===== Copy and Assignment =====" << std::endl;
    MutantStack<int> copyStack(mstack); // copy constructor
    MutantStack<int> assignedStack;
    assignedStack = mstack; // assignment operator

    std::cout << "Iterating over copied stack:" << std::endl;
	
		MutantStack<int>::iterator copied_it = copyStack.begin();
    while (copied_it != copyStack.end())
		{
			std::cout << *copied_it << std::endl;
			copied_it++;
		}

    std::cout << "Iterating over assigned stack:" << std::endl;
		MutantStack<int>::iterator copied_assigned_it = assignedStack.begin();
    while (copied_assigned_it != assignedStack.end())
		{
			std::cout << *copied_assigned_it << std::endl;
			copied_assigned_it++;
		}
}

