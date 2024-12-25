/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/25 23:25:15 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Constructor" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::~Cat()
{
    std::cout << "Cat Destructor" << std::endl;
    delete this->brain;    
}

Cat::Cat(const Cat& obj) : Animal(obj) , Brain(obj)
{
    std::cout << "Cat Copy Constructor" << std::endl;
    *this = obj;
}

Cat& Cat::operator=(const Cat& obj)
{
    std::cout << "Cat Copy Assigment" << std::endl;
    if (this == &obj)
        return (*this);
    this->type = obj.type;
    return(*this);
}

void    Cat::makeSound() const
{
    std::cout << "Miyav!" << std::endl; 
}