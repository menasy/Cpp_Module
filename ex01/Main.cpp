/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:29:49 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/02 00:24:03 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string command;
	PhoneBook phnBook;
	while (true)
	{
		std::cout<<"Enter command: ";
		std::cin>>command;

		// if (command == "EXIT")
		// 	phnBook.exit();
		if (command == "ADD")
			phnBook.add();
		// else if (command == "SEARCH")
		// 	phnBook.search();
	}
}
