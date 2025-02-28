/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:39:01 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/28 21:42:41 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
				Fixed();
				~Fixed();
				Fixed( const Fixed &src );
		Fixed	&operator=( const Fixed &src );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	private:
		int					value;
		static const int	f_bits = 8;
};

#endif
