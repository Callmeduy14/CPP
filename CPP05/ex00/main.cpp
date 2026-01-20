#include "Bureaucrat.hpp"

static void test_construct()
{
	std::cout << "-- construct tests --" << std::endl;
	try
	{
		Bureaucrat a("Alice", 1);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("Bob", 151);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Expected: " << e.what() << std::endl;
	}
}

static void test_inc_dec()
{
	std::cout << "-- inc/dec tests --" << std::endl;
	Bureaucrat c("Carol", 2);
	std::cout << c << std::endl;
	c.incrementGrade();
	std::cout << c << std::endl;
	try
	{
		c.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Expected: " << e.what() << std::endl;
	}
}

int main()
{
	test_construct();
	test_inc_dec();
	return 0;
}
