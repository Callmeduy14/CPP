/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:19:46 by yyudi             #+#    #+#             */
/*   Updated: 2025/10/03 10:20:04 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

Contact::Contact() {}

void Contact::setFirstName(const std::string& v) { _firstName = v; }
void Contact::setLastName(const std::string& v) { _lastName = v; }
void Contact::setNickname(const std::string& v) { _nickname = v; }
void Contact::setPhoneNumber(const std::string& v) { _phoneNumber = v; }
void Contact::setDarkestSecret(const std::string& v) { _darkestSecret = v; }

const std::string& Contact::getFirstName() const { return _firstName; }
const std::string& Contact::getLastName() const { return _lastName; }
const std::string& Contact::getNickname() const { return _nickname; }
const std::string& Contact::getPhoneNumber() const { return _phoneNumber; }
const std::string& Contact::getDarkestSecret() const { return _darkestSecret; }

bool Contact::isValid() const {
	return !_firstName.empty() && !_lastName.empty() && !_nickname.empty()
		&& !_phoneNumber.empty() && !_darkestSecret.empty();
}
