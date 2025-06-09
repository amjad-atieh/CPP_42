/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:57:40 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/09 18:11:32 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int	main()
{
	Data 		*test;
	uintptr_t	raw;

	test = new Data;
	test->a = 55;
	test->c = 'c';
	test->f = 42.01f;

	raw = Serialization::serialize(test);
	std::cout << "raw value: " << raw << std::endl;
	std::cout << "struct pointer value: " << test << std::endl;
	std::cout << "strcut values: " << "a = " << test->a << " f = " << test->f
		<< " c = " << test->c << std::endl;
	std::cout << "deleting pointer value...\n";
	test = NULL;
	test = Serialization::deserialize(raw);
	std::cout << "values deleted\n";
	std::cout << "struct restored pointer value: " << test << std::endl;
	std::cout << "strcut restored values: " << "a = " << test->a << " f = " << test->f
		<< " c = " << test->c << std::endl;
	delete test;
	return 0;
}
