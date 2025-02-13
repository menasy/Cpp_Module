/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:55:24 by menasy            #+#    #+#             */
/*   Updated: 2025/02/13 00:06:23 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade): name(name), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
    	throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
    	throw GradeTooLowException();
    this->isSigned = false;
}
AForm::AForm(): signGrade(0), execGrade(0) {

}

AForm::~AForm() {}

AForm::AForm(const AForm& obj): signGrade(obj.signGrade) , execGrade(obj.execGrade)
{
    *this = obj;
}
    
AForm& AForm::operator=(const AForm& obj) 
{
    (void)obj;
    return(*this);
}
    
const int&	AForm::getSignGrade() const
{
    return(this->signGrade);
}   
         
const std::string&	AForm::getName() const
{
    return (this->name);
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{

	os << obj.getName() << ", Form sign grade " << obj.getSignGrade() << ", Form execute grade " << obj.getExecGrade() << ", Signed status " << obj.getIsSigned();
	return os;

}
//							Exception
char const* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}
char const* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

char const* AForm::FormIsNotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

void AForm::beSigned(const Bureaucrat& obj) 
{
    if (obj.getGrade() <= this->getSignGrade())
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

void AForm::beExecute(const Bureaucrat& obj) const 
{
    if (obj.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw FormIsNotSignedException();
    try{
        executor.executeForm(*this);
        this->executeHandler();    
    }
    catch(std::exception& e){
        (void)e;
    }
}

const bool& AForm::getIsSigned() const
{
    return (this->isSigned);
}

const int&	AForm::getExecGrade() const
{
    return(this->execGrade);
}   

