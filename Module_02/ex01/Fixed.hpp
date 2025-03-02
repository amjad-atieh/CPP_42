/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:39:01 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/02 21:52:44 by aatieh           ###   ########.fr       */
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
				Fixed( const int init_value );
				Fixed( const float init_value );
		Fixed	&operator=( const Fixed &src );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt ( void ) const;
		float	&operator<<( const Fixed &src );
		// std::ostream& operator<<(std::ostream& os, const Fixed& fp);
	private:
		int					value;
		static const int	f_bits = 8;
};

#endif
