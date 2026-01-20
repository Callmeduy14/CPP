#include <stdexcept>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("AForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	validateGrade(_gradeToSign);
	validateGrade(_gradeToExecute);
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	validateGrade(_gradeToSign);
	validateGrade(_gradeToExecute);
}

AForm::AForm(const AForm& other)
: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	validateGrade(_gradeToSign);
	validateGrade(_gradeToExecute);
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::validateGrade(int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat& b)
{
	(void)b;
	// TODO (ex02): same rule as ex01
	throw std::runtime_error("TODO: implement AForm::beSigned");
}

void AForm::execute(const Bureaucrat& executor) const
{
	(void)executor;
	// TODO (ex02):
	// - if not signed -> throw FormNotSignedException
	// - if executor grade too low -> throw GradeTooLowException
	// - otherwise call executeAction()
	throw std::runtime_error("TODO: implement AForm::execute");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "AForm is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "AForm " << f.getName() << " | signed=" << f.getIsSigned()
		<< " | gradeToSign=" << f.getGradeToSign()
		<< " | gradeToExec=" << f.getGradeToExecute();
	return os;
}
