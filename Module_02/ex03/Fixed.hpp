/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:39:01 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/05 06:17:03 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:

		// Constructors
		Fixed();
		~Fixed();
		Fixed( const Fixed &src );
		Fixed( const int init_value );
		Fixed( const float init_value );

		// Operators
		Fixed	&operator=( const Fixed &src );
		bool	operator>( const Fixed &src ) const;
		bool	operator<( const Fixed &src ) const;
		bool	operator>=( const Fixed &src ) const;
		bool	operator<=( const Fixed &src ) const;
		bool	operator==( const Fixed &src ) const;
		bool	operator!=( const Fixed &src ) const;
		Fixed	operator+( const Fixed &src ) const;
		Fixed	operator-( const Fixed &src ) const;
		Fixed	operator*( const Fixed &src ) const;
		Fixed	operator/( const Fixed &src ) const;
		Fixed	&operator++( void );
		Fixed	&operator--( void );
		Fixed	operator++( int );
		Fixed	operator--( int );

		// Member functions
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt ( void ) const;
		
		static const Fixed	&min( const Fixed &a, const Fixed &b );
		static const Fixed	&max( const Fixed &a, const Fixed &b );
		static Fixed		&min( Fixed &a, Fixed &b );
		static Fixed		&max( Fixed &a, Fixed &b );

	private:

		int					value;
		static const int	f_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
