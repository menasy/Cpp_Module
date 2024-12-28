/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/28 23:41:47 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
    std::cout<< "Cure Default Constructor" << std::endl;
    this->type = "cure";
}

Cure::~Cure() 
{
    std::cout<< "Cure Destructor" << std::endl;
}

Cure::Cure(const Cure& obj) : AMateria(obj)
{
    std::cout<< "Cure Copy Constructor" << std::endl;
    *this = obj;
}

Cure& Cure::operator=(const Cure& obj)
{
    std::cout<< "Cure Copy Assigment" << std::endl;
    return (*this);
}

//      AMateria

Cure:: AMateria* clone()
{
     AMateria *obj = new Cure;
	return(obj);
}

void Cure::use(ICharacter& target)
{
    std::cout << "Cure: \"* heals " << target.getName() << "\'s wounds *\"" << std::endl;
    
}