/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:05:43 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/17 16:55:02 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
# define SPAN_TPP

# include "Span.hpp"

template <typename Iter>
void	Span::insert(Iter begin, const Iter end)
{
	while (begin != end)
	{
		addNumber(*begin);
		begin++;
	}
};

#endif
