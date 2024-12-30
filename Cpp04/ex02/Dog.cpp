/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/30 14:18:38 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog()
{
    std::cout << "Dog Constructor" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "Dog Destructor" << std::endl;
    delete this->brain;
}

Dog::Dog(const Dog& obj) : Aanimal(obj), Brain(obj)
{
    std::cout << "Dog Copy Constructor" << std::endl;
    *this = obj;
}

Dog& Dog::operator=(const Dog& obj)
{
    std::cout << "Dog Copy Assigment" << std::endl;

    if (this == &obj) 
        return (*this);
    this->type = obj.type;
    delete this->brain;
    this->brain = new Brain(*obj.brain); 
    for (int i = 0; i < 100; i++)
        this->ideas[i] = obj.ideas[i];
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << "Hav Hav!" << std::endl; 
}