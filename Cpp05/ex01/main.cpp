/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:35:20 by mehmyilm          #+#    #+#             */
/*   Updated: 2025/02/13 00:12:23 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main ()
{
	try{
		
		Bureaucrat brcTadic = Bureaucrat("Dusan Tadic",10);
		Bureaucrat brcDzeko = Bureaucrat("Edin Dzeko",9);

		// Form f1 = Form("Form1",0);
		// Form f2 = Form("Form2",155);
		Form f3 = Form("Form3", 9);
		
		brcTadic.signForm(f3);
		brcDzeko.signForm(f3);
		
	}catch(std::exception &e){
		std::cout<<"Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
