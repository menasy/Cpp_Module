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

#include "Aanimal.hpp"

Aanimal::Aanimal()
{
    std::cout << "Aanimal Constructor" << std::endl;
    this->type = "Aanimal";
}

Aanimal::~Aanimal()
{
    std::cout << "Aanimal Destructor" << std::endl;
    
}


Aanimal::Aanimal(const Aanimal& obj)
{
    std::cout << "Aanimal Copy Constructor" << std::endl;
    *this = obj;
}

Aanimal& Aanimal::operator=(const Aanimal& obj)
{
    std::cout << "Aanimal Copy Assigment" << std::endl;
    if (this == &obj)
        return (*this);
    this->type = obj.type;
    return(*this);
}


std::string Aanimal::getType() const
{
    return(this->type);
}
