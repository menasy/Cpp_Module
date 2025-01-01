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

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixedNum = 0;
	std::cout<<"Default constructor called"<<std::endl;
}
Fixed::Fixed(const Fixed& obj)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = obj;

}
Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this == &other)
		return (*this);
	this->fixedNum = other.getRawBits();
	return(*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return (this->fixedNum);
}


void  Fixed::setRawBits( int const raw )
{
	std::cout<<"setRawBits member function called"<<std::endl;
	this->fixedNum = (raw << fractNum);
}
