/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:10:16 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/27 20:28:34 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contacts.hpp"

class PhoneBook
{
	public:
				PhoneBook();
		void	AddPhoneBook();
		void 	SearchPhoneBook();

	private:
		int		index;
		Contact	contacts[8];
};


#endif
