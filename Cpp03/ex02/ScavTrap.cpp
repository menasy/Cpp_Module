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

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() 
{
    std::cout<<"ScavTrap Default Constructor Called"<<std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;   
}

ScavTrap::~ScavTrap()
{
    std::cout<<"ScavTrap Destructor Called"<<std::endl; 
        
}

ScavTrap::ScavTrap(std::string name) : ClapTrap::ClapTrap(name)
{
    std::cout<<"ScavTrap Name Constructor Called"<<std::endl;
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;   
}

ScavTrap::ScavTrap(const ScavTrap& object) : ClapTrap(object)
{
   std::cout<<"ScavTrap Copy Constructor Called"<<std::endl;
    *this = object;     
}

ScavTrap& ScavTrap::operator=(const ScavTrap& object)
{
     std::cout<<"ScavTrap Copy Assigment Called"<<std::endl;
    if (this == &object)
        return (*this);
    this->hitPoints = object.hitPoints;
    this->attackDamage = object.attackDamage;
    this->energyPoints = object.energyPoints;
    this->name = object.name;
    return(*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energyPoints != 0 && this->hitPoints != 0)
    {
         std::cout<<"ScavTrap "<< this->name << " attacks " << target 
                  << " causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else
        std::cout << "ScavTrap " << this->name << " can't attack!" << std::endl;
    this->showInfos("ScavTrap");
}

void ScavTrap::guardGate() 
{
    std::cout << "ScavTrap " << this->getName() 
              << " is now in Gate Keeper mode!" << std::endl;
}
