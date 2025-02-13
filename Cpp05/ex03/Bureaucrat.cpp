/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:55:24 by menasy            #+#    #+#             */
/*   Updated: 2025/02/12 23:28:50 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
	setGrade(grade);
}
 Bureaucrat::Bureaucrat(){}   
Bureaucrat::~Bureaucrat(){}
    
Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
    *this = obj;
}
    
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
    if (this == &obj)
        return(*this);
		
		this->grade = obj.getGrade();
    return(*this);
}
    
const int&	Bureaucrat::getGrade() const
{
    return(this->grade);
}   
         
const std::string&	Bureaucrat::getName() const
{
    return (this->name);
}

void Bureaucrat::setGrade(int& grade) 
{
	if (grade < 1)
    	throw GradeTooHighException();
	if (grade > 150)
    	throw GradeTooLowException();
	this->grade = grade;
}
void Bureaucrat::IncreaseGrade()
{
	if (this->grade -1 < 1)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::reductGrade()
{
	if (this->grade +1 > 150)
    	throw GradeTooLowException();

	this->grade++;
} 

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{

	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;

}
//							Exception
char const* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high! Must be at least 1.");
}
char const* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low! Must be at most 150.");
}
void Bureaucrat::signForm(AForm& form)
{
	try{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch(const std::exception& e){
		std::cout << *this << " couldn’t sign " << form << " because, " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try{
		form.beExecute(*this);
		std::cout << *this << " execute " << form << std::endl;
	}
	catch(const std::exception& e){
		std::cout << *this << " couldn’t execute " << form << " because, " << e.what() << std::endl;
		throw e;
	}
}   

