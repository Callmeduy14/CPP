#include <stdexcept>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("DefaultForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	validateGrade(_gradeToSign);
	validateGrade(_gradeToExecute);
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	validateGrade(_gradeToSign);
	validateGrade(_gradeToExecute);
}

Form::Form(const Form& other)
: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	validateGrade(_gradeToSign);
	validateGrade(_gradeToExecute);
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form() {}

const std::string& Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::validateGrade(int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void Form::beSigned(const Bureaucrat& b)
{
	(void)b;
	// TODO (ex01):
	// - if bureaucrat grade is high enough (<= _gradeToSign), set _isSigned = true
	// - otherwise throw GradeTooLowException
	throw std::runtime_error("TODO: implement Form::beSigned");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form " << f.getName() << " | signed=" << f.getIsSigned()
		<< " | gradeToSign=" << f.getGradeToSign()
		<< " | gradeToExec=" << f.getGradeToExecute();
	return os;
}
