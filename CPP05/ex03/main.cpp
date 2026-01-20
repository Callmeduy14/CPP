#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Intern someIntern;
	Bureaucrat boss("Boss", 1);

	try
	{
		AForm* f = someIntern.makeForm("robotomy request", "Bender");
		boss.executeForm(*f);
		delete f;
	}
	catch (std::exception& e)
	{
		std::cout << "Intern test: " << e.what() << std::endl;
	}
	return 0;
}
