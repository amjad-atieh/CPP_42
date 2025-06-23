/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:05:43 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/23 17:22:57 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename Iter> void Span::insert(Iter begin, const Iter end)
{
    while (begin != end)
    {
        addNumber(*begin);
        begin++;
    }
};
