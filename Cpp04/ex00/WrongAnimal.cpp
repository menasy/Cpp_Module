/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/25 17:57:04 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Constructor" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor" << std::endl;
    
}


WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
    std::cout << "WrongAnimal Copy Constructor" << std::endl;
    *this = obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
    std::cout << "WrongAnimal Copy Assigment" << std::endl;
    if (this == &obj)
        return (*this);
    this->type = obj.type;
    return(*this);
}


std::string WrongAnimal::getType() const
{
    return(this->type);
}

void    WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal Sound" << std::endl;
}
