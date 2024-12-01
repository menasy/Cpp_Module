/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:40:34 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/01 20:33:46 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

bool Utils::checkChar(std::string str, char c)
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

	while (true)
	{
		std::cout<<quest;
		std::getline(std::cin,line);
		if (line.empty())
			exit (1);
		if (checkChar(line, ' '))
		{
			std::cout<<"Blank value cannot be entered"<<std::endl;
			continue ;
		}
		return (line);
	}
}
