/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:35:20 by mehmyilm          #+#    #+#             */
/*   Updated: 2025/02/13 16:40:27 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
int main ()
{
	try{
		
		Bureaucrat brcDzeko = Bureaucrat("Edin Dzeko",9);
		Bureaucrat brcTadic = Bureaucrat("Dusan Tadic",3);
		Bureaucrat brcIrfan = Bureaucrat("Irfancan",47);
		
		Intern 	internTalisca = Intern();
		AForm*	form;
		
		std::cout<< "\n\t\t\t\t\t\t======= Shrubbery =======" << std::endl;
		form = internTalisca.makeForm("Shrubbery Creation", "Fenrbahce");
		brcIrfan.signForm(*form);
		form->execute(brcDzeko);
		delete form;
		
		std::cout<< "\n\t\t\t\t\t\t======= Robot =======" << std::endl;
		form = internTalisca.makeForm("Robotomy Request", "Osterwlde");
		brcDzeko.signForm(*form);
		form->execute(brcIrfan);
		form->execute(brcDzeko);
		delete form;


		std::cout<< "\n\t\t\t\t\t======= President =======" << std::endl;
		form = internTalisca.makeForm("Presidential Pardon", "Osai");
		brcDzeko.signForm(*form);
		form->execute(brcDzeko);
		form->execute(brcTadic);
		delete form;

		std::cout<< "\n\t\t\t\t\t======= WrongCreateForm =======" << std::endl;
		form = internTalisca.makeForm("Wrong Form", "Form");
		brcIrfan.signForm(*	form);
		form->execute(brcDzeko);
		delete 	form;
		
	}catch(std::exception &e){
		std::cout<<"Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
