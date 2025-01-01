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

Cat::Cat(const Cat& obj) : Aanimal(obj) , Brain(obj)
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
    delete this->brain;
    this->brain = new Brain(*obj.brain); 
    for (int i = 0; i < 100; i++)
        this->ideas[i] = obj.ideas[i];
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "Miyav!" << std::endl; 
}