#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat a("Alice", 42);
	Form f("TaxForm", 50, 20);

	std::cout << a << std::endl;
	std::cout << f << std::endl;

	a.signForm(f); // TODO: implement Form::beSigned to see success/failure
	return 0;
}
