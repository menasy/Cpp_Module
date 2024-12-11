/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/11 23:04:31 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::setLevels()
{
	this->compLevels[0] = "DEBUG";
	this->compLevels[1] = "INFO";
	this->compLevels[2] = "WARNING";
	this->compLevels[3] = "ERROR";
}
void Harl::showComplain(int &check)
{
	void (Harl::*ptrMember[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::cout << "[ " << compLevels[check] << " ]" << std::endl;
	(this->*ptrMember[check])();
	check++;
}
void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! " << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free.\n"
			<< "I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}
void Harl::complain(std::string level)
{
	int check = -1;
	this->setLevels();
	for (int i = 0; i < 4; i++)
		if (compLevels[i] == level.c_str())
			check = i;
	while (check < 4)
	{
		switch (check)
		{
		case 0:
			showComplain(check);
			break;
		case 1:
			showComplain(check);
			break;
		case 2:
			showComplain(check);
			break;
		case 3:
			showComplain(check);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			return;
		}
	}
}
