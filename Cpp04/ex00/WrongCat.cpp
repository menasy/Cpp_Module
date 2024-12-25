/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/25 17:57:48 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat Constructor" << std::endl;
    this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor" << std::endl;
    
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(obj)
{
    std::cout << "WrongCat Copy Constructor" << std::endl;
    *this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
    std::cout << "WrongCat Copy Assigment" << std::endl;
    if (this == &obj)
        return (*this);
    this->type = obj.type;
    return(*this);
}

void    WrongCat::makeSound() const
{
    std::cout << "Miyav wrrr!" << std::endl; 
}