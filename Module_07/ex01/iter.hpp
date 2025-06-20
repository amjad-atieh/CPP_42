/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:31:41 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/11 20:50:54 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include "iter.tpp"

template <typename T, typename B>
void	iter(const T &addr, size_t len, B func);

template <typename T, typename B>
void	iter(T &addr, size_t len, B func);


#endif
