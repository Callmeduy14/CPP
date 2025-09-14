// ex01/main.cpp
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cctype>

static std::string trim(const std::string& s) {
	std::string::size_type start = 0;
	while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start]))) start++;
	std::string::size_type end = s.size();
	while (end > start && std::isspace(static_cast<unsigned char>(s[end-1]))) end--;
	return s.substr(start, end - start);
}

static std::string promptNonEmpty(const std::string& label) {
	std::string line;
	for (;;) {
		std::cout << label;
		if (!std::getline(std::cin, line)) {
			std::cout << std::endl;
			return "";
		}
		line = trim(line);
		if (!line.empty()) return line;
		std::cout << "(Field cannot be empty)\n";
	}
}

static bool isAllDigits(const std::string& s) {
	if (s.empty()) return false;
	for (std::string::size_type i = 0; i < s.size(); ++i) {
		if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
	}
	return true;
}

int main() {
	PhoneBook book;
	std::string cmd;

	for (;;) {
		std::cout << "CMD> ";
		if (!std::getline(std::cin, cmd)) {
			std::cout << std::endl;
			break;
		}
		if (cmd == "EXIT") {
			break;
		} else if (cmd == "ADD") {
			Contact c;
			std::string first = promptNonEmpty("First name: ");
			if (first.empty()) break; // EOF
			std::string last = promptNonEmpty("Last name: ");
			if (last.empty()) break;
			std::string nick = promptNonEmpty("Nickname: ");
			if (nick.empty()) break;
			std::string phone = promptNonEmpty("Phone number: ");
			if (phone.empty()) break;
			std::string secret = promptNonEmpty("Darkest secret: ");
			if (secret.empty()) break;

			c.setFirstName(first);
			c.setLastName(last);
			c.setNickname(nick);
			c.setPhoneNumber(phone);
			c.setDarkestSecret(secret);

			if (!c.isValid()) {
				std::cout << "Contact is invalid (fields must not be empty)." << std::endl;
			} else {
				book.add(c);
				std::cout << "Contact added." << std::endl;
			}
		} else if (cmd == "SEARCH") {
			book.list();
			if (book.size() == 0) continue;
			std::cout << "Index to display: ";
			std::string line;
			if (!std::getline(std::cin, line)) {
				std::cout << std::endl;
				break;
			}
			if (!isAllDigits(trim(line))) {
				std::cout << "Invalid index." << std::endl;
				continue;
			}
			int idx = 0;
			for (std::string::size_type i = 0; i < line.size(); ++i) {
				if (std::isdigit(static_cast<unsigned char>(line[i])))
					idx = idx * 10 + (line[i] - '0');
			}
			if (!book.printByDisplayIndex(idx)) {
				std::cout << "Invalid index." << std::endl;
			}
		} else
		{

		}
	}
	return 0;
}
