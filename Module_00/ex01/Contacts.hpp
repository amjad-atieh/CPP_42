/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:10:59 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/02 17:08:36 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <iostream>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_num;
	std::string	darkest_secret;

public:
			Contact();
	bool	AddContact();
	void	PrintContactColumn();
	bool	ContactEmpty();
	void	PrintContact();
};

#endif
