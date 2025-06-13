/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:35:08 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/13 19:56:23 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &a, T &b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	&min(T &a, T &b)
{
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>
T	&max(T &a, T &b)
{
	if (a > b)
		return a;
	else
		return b;
}

#endif