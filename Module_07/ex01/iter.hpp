/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:31:41 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/23 14:13:01 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include "iter.tpp"

template <typename T>
void	iter(const T addr[], size_t len, void (func)(T const&));

template <typename T>
void	iter(T addr[], size_t len, void (func)(T &));


#endif
