// ex01/PhoneBook.hpp
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook {
public:
	PhoneBook();

	void add(const Contact& c);
	int  size() const;
	void list() const;
	bool printByDisplayIndex(int displayIndex) const;

private:
	Contact _contacts[8];
	int		_size;
	int		_next;

	static std::string formatField(const std::string& s);
	int oldestIndex() const;
	int mapDisplayToInternal(int displayIndex) const;
};

#endif
