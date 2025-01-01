/*
 ███▄ ▄███▓▓█████  ███▄    █  ▄▄▄        ██████▓██   ██▓
▓██▒▀█▀ ██▒▓█   ▀  ██ ▀█   █ ▒████▄    ▒██    ▒ ▒██  ██▒
▓██    ▓██░▒███   ▓██  ▀█ ██▒▒██  ▀█▄  ░ ▓██▄    ▒██ ██░
▒██    ▒██ ▒▓█  ▄ ▓██▒  ▐▌██▒░██▄▄▄▄██   ▒   ██▒ ░ ▐██▓░
▒██▒   ░██▒░▒████▒▒██░   ▓██░ ▓█   ▓██▒▒██████▒▒ ░ ██▒▓░
░ ▒░   ░  ░░░ ▒░ ░░ ▒░   ▒ ▒  ▒▒   ▓▒█░▒ ▒▓▒ ▒ ░  ██▒▒▒
░  ░      ░ ░ ░  ░░ ░░   ░ ▒░  ▒   ▒▒ ░░ ░▒  ░ ░▓██ ░▒░
░      ░      ░      ░   ░ ░   ░   ▒   ░  ░  ░  ▒ ▒ ░░
       ░      ░  ░         ░       ░  ░      ░  ░ ░
                                                ░ ░*/

#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
    std::cout << "========= My Main =========" << std::endl << std::endl;
    const int size = 6;
    Aanimal **aanimal = new Aanimal*[size];
    std::cout<< "========== Object ==========" << std::endl;
    for (int i = 0; i < size; i++)
    {
        if (i < size/2)
            aanimal[i] = new Dog();
        else
            aanimal[i] = new Cat();   
    }
    
    std::cout<<aanimal[0]->getType() << std::endl;
    std::cout<<aanimal[size -1]->getType() << std::endl << std::endl;
    
    aanimal[1]->makeSound();
    aanimal[size -2]->makeSound();
    std::cout<< std::endl;
    for (int i = size -1; i >= 0; i--)
        delete aanimal[i];
        
    delete[] aanimal;
    std::cout << "\n===========================" << std::endl;
    return (0);
}