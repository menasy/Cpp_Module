/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:55:24 by menasy            #+#    #+#             */
/*   Updated: 2025/02/10 17:57:14 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{

    this->name = name;
	setGrade(grade);
}
    
Bureaucrat::~Bureaucrat(){}
    
Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
    *this = obj;
}
    
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
    if (this == &obj)
        return(*this);
    this->name = obj.name;
	this->grade = obj.grade;
    return(*this);
}
    
int	Bureaucrat::getGrade()
{
    return(this->grade);
}   
         
std::string	Bureaucrat::getName()
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

//							Exception
char const* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high! Must be at least 1.");
}
char const* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low! Must be at most 150.");
}
