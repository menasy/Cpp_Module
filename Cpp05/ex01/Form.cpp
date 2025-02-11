/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:55:24 by menasy            #+#    #+#             */
/*   Updated: 2025/02/11 22:54:11 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int signGrade): name(name), signGrade(signGrade), execGrade(0)
{
	if (signGrade < 1)
    	throw GradeTooHighException();
	else if (signGrade > 150)
    	throw GradeTooLowException();
    this->isSigned = false;
}
Form::Form(): signGrade(0), execGrade(0) {}

Form::~Form() {}

Form::Form(const Form& obj): signGrade(obj.signGrade) , execGrade(obj.execGrade)
{
    *this = obj;
}
    
Form& Form::operator=(const Form& obj) 
{
    (void)obj;
    return(*this);
}
    
const int&	Form::getSignGrade() const
{
    return(this->signGrade);
}   
         
const std::string&	Form::getName() const
{
    return (this->name);
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{

	os << obj.getName() << ", Form grade " << obj.getSignGrade() << ", Signed status " << obj.getIsSigned();
	return os;

}
//							Exception
char const* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}
char const* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

void Form::beSigned(const Bureaucrat& obj) 
{
    if (obj.getGrade() <= this->getSignGrade())
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

const bool& Form::getIsSigned() const
{
    return (this->isSigned);
}

const int&	Form::getExecGrade() const
{
    return(this->execGrade);
}   

