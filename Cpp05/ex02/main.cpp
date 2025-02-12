/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:35:20 by mehmyilm          #+#    #+#             */
/*   Updated: 2025/02/13 00:09:27 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main ()
{
	try{
		
		Bureaucrat brcDzeko = Bureaucrat("Edin Dzeko",9);
		Bureaucrat brcTadic = Bureaucrat("Dusan Tadic",3);
		Bureaucrat brcIrfan = Bureaucrat("Irfancan",47);
		
		
		ShrubberyCreationForm shruberryForm = ShrubberyCreationForm("Fenerbahce");
		RobotomyRequestForm robotForm = RobotomyRequestForm("Osterwolde");
		PresidentialPardonForm presidentForm = PresidentialPardonForm("Osayi");

		
		std::cout<< "\n\t\t\t\t\t\t======= Shrubbery =======" << std::endl;
		brcIrfan.signForm(shruberryForm);
		shruberryForm.execute(brcDzeko);
		
		std::cout<< "\n\t\t\t\t\t\t======= Robot =======" << std::endl;
		brcDzeko.signForm(robotForm);
		robotForm.execute(brcIrfan);
		robotForm.execute(brcDzeko);

		std::cout<< "\n\t\t\t\t\t======= President =======" << std::endl;
		brcDzeko.signForm(presidentForm);
		presidentForm.execute(brcDzeko);
		presidentForm.execute(brcTadic);
	
	}catch(std::exception &e){
		std::cout<<"Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
