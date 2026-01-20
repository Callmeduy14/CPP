#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

protected:
	AForm();
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);

public:
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	const std::string&	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	void				beSigned(const Bureaucrat& b); // TODO
	void				execute(const Bureaucrat& executor) const; // TODO checks + call action

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

protected:
	virtual void		executeAction() const = 0; // implemented by derived forms

private:
	void				validateGrade(int grade) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
