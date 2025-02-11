/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:35:20 by mehmyilm          #+#    #+#             */
/*   Updated: 2025/02/11 22:16:49 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
void displayIncraseInfo(Bureaucrat& brc)
{
	std::cout << "Before Incrase: " << brc <<std::endl;
	brc.IncreaseGrade();
	std::cout  << "After Incrase: "<< brc <<std::endl << std::endl;
}

void displayReductionInfo(Bureaucrat& brc)
{
	std::cout << "Before Redurction: " << brc <<std::endl;
	brc.reductGrade();
	std::cout  << "After Reduction: " << brc<<std::endl << std::endl;
}
int main ()
{
	try{
		//  Bureaucrat brcIrfan = Bureaucrat("İrfancan Kahveci",-1);
		//  Bureaucrat brcSebo = Bureaucrat("Symanski",151);
		Bureaucrat brcTadic = Bureaucrat("Dusan Tadic",10);
		Bureaucrat brcDzeko = Bureaucrat("Edin Dzeko",9);
		Form f1 = Form("Form1", 17);
		
		brcTadic.signForm(f1);
		
	}catch(std::exception &e){
		std::cout<<"Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
