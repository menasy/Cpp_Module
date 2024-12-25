/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/25 17:31:06 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Constructor" << std::endl;
    this->type = "Animal";
}

Animal::~Animal()
{
    std::cout << "Animal Destructor" << std::endl;
    
}


Animal::Animal(const Animal& obj)
{
    std::cout << "Animal Copy Constructor" << std::endl;
    *this = obj;
}

Animal& Animal::operator=(const Animal& obj)
{
    std::cout << "Animal Copy Assigment" << std::endl;
    if (this == &obj)
        return (*this);
    this->type = obj.type;
    return(*this);
}


std::string Animal::getType() const
{
    return(this->type);
}

void    Animal::makeSound() const
{
    std::cout << "Animal Sound" << std::endl;
}
