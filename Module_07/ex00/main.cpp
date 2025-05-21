/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:22:11 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/21 20:29:55 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

struct test
{
	int example;
};

template <typename T>
void	swap(T &a, T &b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	min(T &a, T &b)
{
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>
T	max(T &a, T &b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main( void ) {

int a = 2;
int b = 3;

::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

std::string c = "chaine1";
std::string d = "chaine2";

::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

// struct test e;
// struct test f;

// ::swap(e, f);
// ::min( e, f );
// ::max( f, e );

return 0;
	
}
