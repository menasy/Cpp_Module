/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/09 16:12:33 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
	:name(name), weapon(weapon) {}
void	HumanA::attack()
{
	std::cout<< HumanA::getName() << " attacks with their " << HumanA::getWeapon() << std::endl;
}

std::string	HumanA:: getName()
{
	return(this->name);
}
std::string	HumanA:: getWeapon()
{
	return(this->weapon.getType());
}
void	HumanA:: setName(std::string& name)
{
	this->name = name;
}

