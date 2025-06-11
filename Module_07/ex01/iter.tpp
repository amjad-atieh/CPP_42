/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:49:47 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/11 20:50:58 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>

template <typename T, typename B>
void	iter(const T &addr, size_t len, B func)
{
	for (size_t i = 0; i < len; i++)
		func(addr[i]);
}

template <typename T, typename B>
void	iter(T &addr, size_t len, B func)
{
	for (size_t i = 0; i < len; i++)
		func(addr[i]);
}
