/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:35:20 by mehmyilm          #+#    #+#             */
/*   Updated: 2025/02/10 17:59:42 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


void setGrade(int& grade)
{
	try{
		if (grade < 1)
    		throw GradeTooHighException();
	}catch(GradeTooHighException &e){
		std::cout<<"Exception caught: " << e.what() << std::endl;
	}
	try{
		if (grade > 150)
    		throw GradeTooLowException();
	}catch(GradeTooLowException &e){
		std::cout<<"Exception caught: " << e.what() << std::endl;
	}
	this->grade = grade;
}

int main ()
{


}
