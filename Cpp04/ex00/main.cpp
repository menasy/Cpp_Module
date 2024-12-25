/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/25 18:27:41 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include  "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal *wrAn = new WrongCat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << wrAn->getType() << " " << std::endl;
    
    
    i->makeSound(); 
    j->makeSound();
    meta->makeSound();
    wrAn->makeSound();

    delete j;
    delete i;
    delete meta;
    delete wrAn;

    return (0);
}