/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:28:07 by menasy            #+#    #+#             */
/*   Updated: 2025/02/13 16:55:25 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){} 
Intern::~Intern(){}
Intern::Intern(const Intern& obj){*this = obj;}
Intern& Intern::operator=(const Intern& obj){
    (void)obj;
    return(*this);
}

char const* Intern::FormNotExists::what() const throw()
{
	return ("Form with the given name does not exist.");
}
std::string Intern::toLowerStr(std::string& str)
{
    const char *newStr = str.c_str();
    std::string dest;
    int i = 0;
    while (newStr[i])
        dest += tolower(newStr[i++]);
    return dest;
} 
AForm*	Intern::createShrubberyCreation(std::string& target)
{
    AForm *form =  new ShrubberyCreationForm(target);
	return(form);
}
AForm*	Intern::createRobotomyRequest(std::string& target)
{
    AForm *form =  new  RobotomyRequestForm(target);
	return(form);
}
AForm*	Intern::createPresidentialPardon(std::string& target)
{
    AForm *form =  new  PresidentialPardonForm(target);
	return(form);
}


AForm* Intern::makeForm(std::string formType, std::string formTarget)
{
	if (formType.empty() || formTarget.empty())
		throw FormNotExists();
    std::string lowerStr = toLowerStr(formType);
	
    std::string formLst[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
    AForm* (Intern:: *ptrMember[3])(std::string&) = {&Intern::createShrubberyCreation,
			&Intern::createRobotomyRequest, &Intern::createPresidentialPardon};
			
	for (int i = 0; i < 3; i++)
	{
		if (lowerStr == formLst[i])
		{
			AForm *form = (this->*ptrMember[i])(formTarget);
			std::cout << "\033[1;33m" << "Intern create " << *form << "\033[0m" << std::endl;
			return(form);
		}
	}
	throw FormNotExists();
}
