/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:09:53 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/23 17:17:11 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template <typename T>
bool	easyfind(const T &cn, const int num)
{
	if (std::find(cn.begin(), cn.end(), num) == cn.end())
		return false;
	else
		return true;
}

#endif
