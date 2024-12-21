/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/21 21:30:37 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
{
    std::cout<<"DiamondTrap Default Constructor Called"<<std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;   
}

DiamondTrap::~DiamondTrap()
{
    std::cout<<"DiamondTrap Destructor Called"<<std::endl; 
        
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap::ClapTrap(name)
{
    std::cout<<"DiamondTrap Name Constructor Called"<<std::endl;
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;   
}

DiamondTrap::DiamondTrap(const DiamondTrap& object) : ClapTrap(object)
{
   std::cout<<"DiamondTrap Copy Constructor Called"<<std::endl;
    *this = object;     
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& object)
{
     std::cout<<"DiamondTrap Copy Assigment Called"<<std::endl;
    if (this == &object)
        return (*this);
    this->hitPoints = object.hitPoints;
    this->attackDamage = object.attackDamage;
    this->energyPoints = object.energyPoints;
    this->name = object.name;
    return(*this);
}

void DiamondTrap::attack(const std::string& target)
{
	    if (this->energyPoints != 0 && this->hitPoints != 0)
    {
         std::cout<<"DiamondTrap "<< this->name << " attacks " << target 
            << " causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else
        std::cout << "DiamondTrap " << this->name << " can't attack!" << std::endl;
    this->showInfos("DiamondTrap");
}