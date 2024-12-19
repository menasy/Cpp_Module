/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/19 17:22:28 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout<<"ClapTrap Default Constructor Called"<<std::endl;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout<<"ClapTrap Destructor Called"<<std::endl; 
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout<<"ClapTrap Name Constructor Called"<<std::endl;
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& object)
{
    std::cout<<"ClapTrap Copy Constructor Called"<<std::endl;
    *this = object;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& object)
{
    std::cout<<"ClapTrap Copy Assigment Called"<<std::endl;
    if (this == &object)
        return (*this);
    this->hitPoints = object.hitPoints;
    this->attackDamage = object.attackDamage;
    this->energyPoints = object.energyPoints;
    this->name = object.name;
    return(*this);
}
const std::string& ClapTrap::getName(void) const
{
    return(this->name);
}
const int& ClapTrap::getHitPoints(void) const
{
    return(this->hitPoints);
}
const int& ClapTrap::getEnergyPoints(void) const
{
    return(this->energyPoints);
}
const int& ClapTrap::getAttackDamage(void) const
{
    return(this->attackDamage);
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energyPoints != 0 && this->hitPoints != 0)
    {
         std::cout<<"ClapTrap "<< this->name << " attacks " << target 
            << " causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
        this->showInfos();
    }
    else
        std::cout << "ClapTrap " << this->name << " can't attack!" << std::endl;
   
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints == 0)
        std::cout << "ClapTrap " << this->name << " takes damage " << amount << " and is already unconscious." << std::endl;
    if ((int)amount <= 0)
        std::cout << "ClapTrap " << this->name << " did not take any damage." <<std::endl;
    else if (this->hitPoints != 0)
    {
        std::cout<< "ClapTrap " << this->name << " take damage " << amount << std::endl;
        this->hitPoints -= amount; 
        if (this->hitPoints <= 0)
        {
            std::cout << "ClapTrap " << this->name << " is unconscious." << std::endl;
            this->hitPoints = 0;
        }
        this->showInfos();
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoints != 0 && (int)amount > 0 )
    {
        std::cout << "ClapTrap " << this->name << " repairs itself, regaining " 
                << amount << " hit points!" << std::endl;
        this->hitPoints += amount;
        this->energyPoints--;
        this->showInfos();
    }
    else
        std::cout << "ClapTrap " << this->name << " can't repair itself." << std::endl;

}
void ClapTrap::showInfos() {
    std::cout << "\033[32mClapTrap " << this->getName() 
              << " Hit Points ( " << this->getHitPoints() << " )"
              << " Energy Points ( " << this->getEnergyPoints() << " )\033[0m" 
              << std::endl;
}


