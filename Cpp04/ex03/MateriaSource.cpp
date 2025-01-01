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

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->initInventory();
}

MateriaSource::~MateriaSource()
{
	this->deleteInventory();	
}

MateriaSource::MateriaSource(MateriaSource const &obj)
{
    *this = obj;
}

MateriaSource& MateriaSource::operator=(MateriaSource const &obj)
{
    if (this == &obj)
        return(*this);
    this->deleteInventory();
    for (int i = 0; i < 4; i++)
    {
        if (obj.mInventory[i] != NULL)
            this->mInventory[i] = obj.mInventory[i]->clone();
        else
            this->mInventory[i] = NULL;       
    }
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