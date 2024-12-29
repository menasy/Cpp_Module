/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/29 21:18:05 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
    std::cout<< "Ice Default Constructor" << std::endl;
	this->type = "ice";
}

Ice::~Ice() 
{
    std::cout<< "Ice Destructor" << std::endl;
}

Ice::Ice(const Ice& obj) : AMateria(obj)
{
    std::cout<< "Ice Copy Constructor" << std::endl;
    *this = obj;
}

Ice& Ice::operator=(const Ice& obj)
{
    std::cout<< "Ice Copy Assigment" << std::endl;
    if (this == &obj)
        return (*this);
    *this = obj;
    return (*this);
}

//          Amateria

AMateria* Ice::clone() const
{
    AMateria *obj = new Ice;
	return(obj);
}

void Ice::use(ICharacter& target)
{
    std::cout << "Ice: \"* shoots an ice bolt at " << target.getName() << " *\"" << std::endl;
}
