/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:05:52 by tbaker            #+#    #+#             */
/*   Updated: 2024/11/11 18:09:31 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <string>

class Contact{

	public:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
		Contact(void);
		void inputContact(void);

	private:
		void _assignInput(std::string& var, const char* txt);
		bool _stringIsEmpty(std::string& input);
};

#endif
