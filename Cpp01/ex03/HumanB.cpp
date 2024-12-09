/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/09 17:22:56 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->setName(name);
	this->weapon = NULL;
}
void	HumanB::attack()
{
	if (this->weapon == NULL)
		std::cout<< HumanB::getName() << " no weapon !"<<std::endl;
	else
		std::cout<< HumanB::getName() << " attacks with their " << this->weapon->getType() << std::endl;

}

std::string	HumanB:: getName()
{
	return(this->name);
}
void	HumanB:: setName(std::string& name)
{
	this->name = name;
}

void	HumanB:: setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}
