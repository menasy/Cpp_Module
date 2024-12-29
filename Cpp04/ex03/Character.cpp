/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/30 00:43:24 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    this->initInventory();
}
Character::Character(std::string name)
{
    this->name = name;
    this->initInventory();
}

Character::~Character() 
{
    this->deleteInventory();
	delete[] this->inventory;
}

Character::Character(const Character& obj) 
{
    *this = obj;
}

Character& Character::operator=(const Character& obj)
{
    if (this == &obj)
        return(*this);
    this->name = obj.name;
    for (int i = 0; i < 4; i++)
    {
        delete this->inventory[i];
        this->inventory[i] = NULL;
    }
    for (int i = 0; i < 4; i++)
    {
        if (obj.inventory[i] != NULL)
            this->inventory[i] = obj.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
        
    }
    return (*this);
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (m == NULL)
        return ;
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
    this->tmp[idx] = this->inventory[idx];
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
        delete this->tmp[i];
		this->tmp[i] = NULL;
		this->inventory[i] = NULL;
	}
}

void   Character::initInventory()
{      
    this->inventory = new AMateria*[4];
    for (int i = 0; i < 4; i++)
    {
         this->inventory[i] = NULL;
         this->tmp[i] = NULL;
        
    }
}