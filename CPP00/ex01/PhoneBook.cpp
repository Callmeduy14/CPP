// ex01/PhoneBook.cpp
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _size(0), _next(0) {}

void PhoneBook::add(const Contact& c) {
	_contacts[_next] = c;
	_next = (_next + 1) % 8;
	if (_size < 8) _size++;
}

int PhoneBook::size() const { return _size; }

int PhoneBook::oldestIndex() const {
	// If not full, oldest is 0; if full, oldest is _next (the one to be overwritten next)
	return (_size < 8) ? 0 : _next;
}

int PhoneBook::mapDisplayToInternal(int displayIndex) const {
	if (displayIndex < 0 || displayIndex >= _size) return -1;
	return (oldestIndex() + displayIndex) % _size;
}

std::string PhoneBook::formatField(const std::string& s) {
	if (s.size() <= 10) {
		std::string pad = s;
		return pad;
	} else {
		return s.substr(0, 9) + ".";
	}
}

void PhoneBook::list() const {
	if (_size == 0) {
		std::cout << "PhoneBook empty." << std::endl;
		return;
	}
	std::cout << std::setw(10) << "index" << "|"
			  << std::setw(10) << "first name" << "|"
			  << std::setw(10) << "last name" << "|"
			  << std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < _size; ++i) {
		int idx = mapDisplayToInternal(i);
		const Contact& c = _contacts[idx];
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << formatField(c.getFirstName()) << "|"
				  << std::setw(10) << formatField(c.getLastName()) << "|"
				  << std::setw(10) << formatField(c.getNickname()) << std::endl;
	}
}

bool PhoneBook::printByDisplayIndex(int displayIndex) const {
	int idx = mapDisplayToInternal(displayIndex);
	if (idx < 0) return false;
	const Contact& c = _contacts[idx];
	std::cout << "First name	: " << c.getFirstName() << std::endl;
	std::cout << "Last name		: " << c.getLastName() << std::endl;
	std::cout << "Nickname		: " << c.getNickname() << std::endl;
	std::cout << "Phone number	: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
	return true;
}
