/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:05:04 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/23 19:48:10 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main()
{
	std::cout << "================ my output ================" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(564);
		mstack.push(786);
		mstack.push(876);
		mstack.push(7937);
		mstack.push(45);
		mstack.push(788);
		mstack.push(7);
		mstack.push(78);
		mstack.push(754637);
		mstack.push(5432);
		mstack.push(557);
		mstack.push(45687);
		mstack.push(2354);
		mstack.push(587);
		mstack.push(632);
		mstack.push(737);
		mstack.push(548);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "================ perfect output ================" << std::endl;
	{
		std::deque<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << std::endl;

		mstack.pop_back();

		std::cout << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(564);
		mstack.push_back(786);
		mstack.push_back(876);
		mstack.push_back(7937);
		mstack.push_back(45);
		mstack.push_back(788);
		mstack.push_back(7);
		mstack.push_back(78);
		mstack.push_back(754637);
		mstack.push_back(5432);
		mstack.push_back(557);
		mstack.push_back(45687);
		mstack.push_back(2354);
		mstack.push_back(587);
		mstack.push_back(632);
		mstack.push_back(737);
		mstack.push_back(548);
		mstack.push_back(0);

		std::deque<int>::iterator it = mstack.begin();
		std::deque<int>::iterator ite = mstack.end();

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;
}
