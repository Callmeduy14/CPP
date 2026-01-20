#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Bureaucrat boss("Boss", 1);
	ShrubberyCreationForm s("home");
	RobotomyRequestForm r("Bender");
	PresidentialPardonForm p("Arthur");

	std::cout << boss << std::endl;
	std::cout << s << std::endl;

	// TODO: implement signing + executing in AForm & actions in derived forms
	boss.executeForm(s);
	boss.executeForm(r);
	boss.executeForm(p);
	return 0;
}
