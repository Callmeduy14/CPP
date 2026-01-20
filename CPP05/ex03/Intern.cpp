#include <iostream>
#include <stdexcept>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }
Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	(void)formName;
	(void)target;
	// TODO (ex03): implement a clean mapping without a giant if/else chain.
	// Expected names in subject examples:
	// - "shrubbery creation"
	// - "robotomy request"
	// - "presidential pardon"
	// Return new <Form>(target) or NULL (or throw) with a clear message.
	throw std::runtime_error("TODO: implement Intern::makeForm");
}
