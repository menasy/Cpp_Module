/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/11 23:10:49 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **argv)
{
	Harl harl1;
	std::string level;
	void (Harl::*ptrCoomp)(std::string) = &Harl::complain;

	level = argv[1];
	if (ac != 2 || level.empty())
	{
		std::cout<< "No complaint !" <<std::endl;
		return (0);
	}
	(harl1.*ptrCoomp)(level);
}
