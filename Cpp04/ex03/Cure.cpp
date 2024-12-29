/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/29 21:29:31 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
    this->type = "cure";
}

Cure::~Cure() {}

Cure::Cure(const Cure& obj) : AMateria(obj)
{
    *this = obj;
}

Cure& Cure::operator=(const Cure& obj)
{
    if (this == &obj)
        return (*this);
    *this = obj;
    return (*this);
}

//      AMateria

AMateria* Cure::clone() const
{
    AMateria *obj = new Cure;
	return(obj);
}

void Cure::use(ICharacter& target)
{
    std::cout << "Cure: * heals " << target.getName() << "\'s wounds *" << std::endl;
    
}