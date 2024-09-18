/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 23:28:46 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/09/18 23:55:39 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
int main()
{
	std::string input;

	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input.empty())
			continue;
		if (!input.compare("ADD"))
			std::cout <<"add" << std::endl;
		else if (!input.compare("SEARCH"))
			std::cout <<"search" << std::endl;
		else if (!input.compare("EXIT"))
			std::cout <<"exit" << std::endl;
		else
			std::cout << "Invalid Command !" << std::endl;

	}
}
