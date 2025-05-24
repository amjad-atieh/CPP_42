/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:26:14 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/23 19:26:14 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>

class RPN
{
	public:
		// Constructors
		RPN();
		RPN(const RPN &copy);
		
		// Destructor
		~RPN();
		
		// Operators
		RPN & operator=(const RPN &assign);
		
	private:
		
};

#endif