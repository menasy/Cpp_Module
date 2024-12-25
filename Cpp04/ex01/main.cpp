/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/26 00:04:48 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
    {
        std::cout << "========= Subject Main =========" << std::endl<< std::endl;
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;//should not create a leak
        delete i;
        std::cout << "\n===========================" << std::endl;

    }
    {
        std::cout << "========= My Main =========" << std::endl << std::endl;
        const int size = 10;
        Animal **animal = new Animal*[size];
        
        for (int i = 0; i < size; i++)
        {
            if (i < size/2)
                animal[i] = new Dog();
            else
                animal[i] = new Cat();   
        }
        
        std::cout<<animal[0]->getType() << std::endl;
        std::cout<<animal[size -1]->getType() << std::endl << std::endl;
        
        animal[1]->makeSound();
        animal[size -2]->makeSound();
        std::cout<< std::endl;

        for (int i = size -1; i >= 0; i--)
            delete animal[i];
            
        delete[] animal;
        std::cout << "\n===========================" << std::endl;
    }
    return (0);
}