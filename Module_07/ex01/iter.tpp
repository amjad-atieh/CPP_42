/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:49:47 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/23 14:14:32 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>

template <typename T>
void	iter(const T addr[], size_t len, void (func)(T const&))
{
	for (size_t i = 0; i < len; i++)
		func(addr[i]);
}

template <typename T>
void	iter(T addr[], size_t len, void (func)(T &))
{
	for (size_t i = 0; i < len; i++)
		func(addr[i]);
}
