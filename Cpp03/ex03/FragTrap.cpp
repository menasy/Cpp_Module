/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/22 23:27:46 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() 
{
    std::cout<<"FragTrap Default Constructor Called"<<std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;   
}

FragTrap::~FragTrap()
{
    std::cout<<"FragTrap Destructor Called"<<std::endl; 
        
}

FragTrap::FragTrap(std::string newName) : ClapTrap::ClapTrap(newName)
{
    std::cout<<"FragTrap Name Constructor Called"<<std::endl;
    this->name = newName;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;   
}

FragTrap::FragTrap(const FragTrap& object) : ClapTrap(object)
{
   std::cout<<"FragTrap Copy Constructor Called"<<std::endl;
    *this = object;     
}

FragTrap& FragTrap::operator=(const FragTrap& object)
{
     std::cout<<"FragTrap Copy Assigment Called"<<std::endl;
    if (this == &object)
        return (*this);
    this->hitPoints = object.hitPoints;
    this->attackDamage = object.attackDamage;
    this->energyPoints = object.energyPoints;
    this->name = object.name;
    return(*this);
}

void FragTrap::attack(const std::string& target)
{
	    if (this->energyPoints != 0 && this->hitPoints != 0)
    {
         std::cout<<"FragTrap "<< this->name << " attacks " << target 
            << " causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else
        std::cout << "FragTrap " << this->name << " can't attack!" << std::endl;
    this->showInfos("FragTrap");
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->getName() 
              << " says: \"High five, team! Let's celebrate with an epic victory clap! ✋🤖\"" << std::endl;
}


