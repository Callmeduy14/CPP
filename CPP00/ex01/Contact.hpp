/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:19:50 by yyudi             #+#    #+#             */
/*   Updated: 2025/10/03 10:19:51 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ex01/Contact.hpp
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
	Contact();

	void setFirstName(const std::string& v);
	void setLastName(const std::string& v);
	void setNickname(const std::string& v);
	void setPhoneNumber(const std::string& v);
	void setDarkestSecret(const std::string& v);

	const std::string& getFirstName() const;
	const std::string& getLastName() const;
	const std::string& getNickname() const;
	const std::string& getPhoneNumber() const;
	const std::string& getDarkestSecret() const;

	bool isValid() const;

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif
