/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/08 20:21:58 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string &ref = brain;
	std::string *ptr;

	ptr = &brain;
	std::cout<<"STR Memory Adress: "<<&brain<<std::endl;
	std::cout<<"PTR Memory Adress: "<<ptr<<std::endl;
	std::cout<<"REF Memory Adress: "<<&ref<<std::endl;
	std::cout<<std::endl;
	std::cout<<"STR Values: "<<brain<<std::endl;
	std::cout<<"PTR Values: "<<*ptr<<std::endl;
	std::cout<<"REF Values: "<<ref<<std::endl;

	return (0);
}

