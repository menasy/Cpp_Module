/*
 ███▄ ▄███▓▓█████  ███▄    █  ▄▄▄        ██████▓██   ██▓
▓██▒▀█▀ ██▒▓█   ▀  ██ ▀█   █ ▒████▄    ▒██    ▒ ▒██  ██▒
▓██    ▓██░▒███   ▓██  ▀█ ██▒▒██  ▀█▄  ░ ▓██▄    ▒██ ██░
▒██    ▒██ ▒▓█  ▄ ▓██▒  ▐▌██▒░██▄▄▄▄██   ▒   ██▒ ░ ▐██▓░
▒██▒   ░██▒░▒████▒▒██░   ▓██░ ▓█   ▓██▒▒██████▒▒ ░ ██▒▓░
░ ▒░   ░  ░░░ ▒░ ░░ ▒░   ▒ ▒  ▒▒   ▓▒█░▒ ▒▓▒ ▒ ░  ██▒▒▒
░  ░      ░ ░ ░  ░░ ░░   ░ ▒░  ▒   ▒▒ ░░ ░▒  ░ ░▓██ ░▒░
░      ░      ░      ░   ░ ░   ░   ▒   ░  ░  ░  ▒ ▒ ░░
       ░      ░  ░         ░       ░  ░      ░  ░ ░
                                                ░ ░*/

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
{
    std::cout<<"DiamondTrap Default Constructor Called"<<std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;   
}

DiamondTrap::~DiamondTrap()
{
    std::cout<<"DiamondTrap Destructor Called"<<std::endl; 
        
}

DiamondTrap::DiamondTrap(std::string newName) : ClapTrap::ClapTrap(newName + "_clap_name")
{
    std::cout<<"DiamondTrap Name Constructor Called"<<std::endl;
    this->name = newName;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;   
}

DiamondTrap::DiamondTrap(const DiamondTrap& object) 
            : ClapTrap(object), FragTrap(object), ScavTrap(object) 
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
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout<<"DiamondTrap Name: " << this->name <<std::endl;
    std::cout<<"ClapTrap Name: " << ClapTrap::name <<std::endl << std::endl;
}