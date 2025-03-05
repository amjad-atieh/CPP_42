/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:39:01 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/05 06:16:38 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:

		// Constructors
		Fixed();
		Fixed( const Fixed &src );

		// Destructor
		~Fixed();

		// Operators
		Fixed	&operator=( const Fixed &src );

		// Member functions
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:

		int					value;
		static const int	f_bits = 8;
};

#endif
