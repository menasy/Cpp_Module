/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:40:34 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/02 00:48:12 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

bool Utils::checkChar(std::string &str, char c)
{
	int	i = -1;

	while (str[++i])
		if (str[i] != c)
			return(false);
	return(true);
}
std::string Utils::addBook(std::string quest)
{
	std::string line;


	while (1)
	{
		std::cout<<"\n"<<quest<<"\n=";
		// std::cout<<"line: " << line.length()<<std::endl;
		std::getline(std::cin,line);
		// if (line.empty())
		// 	exit(1);
		if (checkChar(line, ' '))
		{
			std::cout<<"\nBlank value cannot be entered"<<std::endl;
			continue ;
		}
		return (line);
	}
}
