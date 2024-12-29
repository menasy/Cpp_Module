/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/29 16:48:08 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource Default Constructor" << std::endl;
	this->initInventory();
}

MateriaSource::~MateriaSource()
{
    std::cout<< "MateriaSource Destructor" << std::endl;
	this->deleteInventory();	
}

MateriaSource::MateriaSource(MateriaSource const &obj)
{
	std::cout<< "MateriaSource Copy Constructor" << std::endl;
    *this = obj;
}

MateriaSource& MateriaSource::operator=(MateriaSource const &obj)
{
	std::cout<< "MateriaSource Copy Assigment" << std::endl;
    if (this == &obj)
        return(*this);
    this->deleteInventory();
    for (int i = 0; i < 4; i++)
        this->mInventory[i] = obj.mInventory[i]->clone();
    return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m == NULL)
        return;
    if (m->getType() == "ice" || m->getType() == "cure")
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->mInventory[i] == NULL)
            {
                this->mInventory[i] = m;
                return;
            }
        }
    }
	
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
        if (this->mInventory[i]->getType() == type)
            return (mInventory[i]);
	return (NULL);
}

void   MateriaSource::deleteInventory()
{
    for (int i = 0; i < 4; i++)
	{
        delete this->mInventory[i];
		this->mInventory[i] = NULL;
	}
}

void   MateriaSource::initInventory()
{
    for (int i = 0; i < 4; i++)
         this->mInventory[i] = NULL;
}