/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/29 21:18:14 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    std::cout<< "Character Default Constructor" << std::endl;
    this->initInventory();
}
Character::Character(std::string name)
{
    std::cout<< "Character Name Constructor" << std::endl;
    this->name = name;
    this->initInventory();
}

Character::~Character() 
{
    std::cout<< "Character Destructor" << std::endl;
    this->deleteInventory();
	delete[] this->inventory;
}

Character::Character(const Character& obj) 
{
    std::cout<< "Character Copy Constructor" << std::endl;
    *this = obj;
}

Character& Character::operator=(const Character& obj)
{
    std::cout<< "Character Copy Assigment" << std::endl;
    if (this == &obj)
        return(*this);
    this->name = obj.name;
    this->deleteInventory();
    for (int i = 0; i < 4; i++)
        this->inventory[i] = obj.inventory[i]->clone();
    return (*this);
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == NULL)
        {
            this->inventory[i] = m->clone();
            return;
        }
    }
}

void Character::unequip(int idx)
{
   if (idx < 0 || idx > 3 || this->inventory[idx] == NULL)
		return ;
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3 || this->inventory[idx] == NULL)
		return ;
	this->inventory[idx]->use(target);
}
void   Character::deleteInventory()
{
    for (int i = 0; i < 4; i++)
	{
        delete this->inventory[i];
		this->inventory[i] = NULL;
	}
}

void   Character::initInventory()
{      
    this->inventory = new AMateria*[4];
    for (int i = 0; i < 4; i++)
         this->inventory[i] = NULL;
}