/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/25 17:31:06 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(){}

AMateria::AMateria(std::string const &type)
{
    this->type = type;
}

AMateria:: ~AMateria(){}

AMateria::AMateria(AMateria const &obj)
{
    *this = obj;
}

AMateria& AMateria::operator=(AMateria const &obj)
{
    if (this == &obj)
        return (*this);
    this->type = obj.type;
    return (*this);
}

std::string const& AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria Use Method: " << target.getName() << std::endl;
}
