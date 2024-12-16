/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/16 18:22:11 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called"<<std::endl;
	this->fixedNum = 0;
}
Fixed::Fixed(const int number)
{
	std::cout<<"Int constructor called"<<std::endl;
	this->fixedNum = (number * fractVal);
}
Fixed::Fixed(const float number)
{
	std::cout<<"Float constructor called"<<std::endl;
	this->fixedNum = roundf(number * fractVal);

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
	this->fixedNum = other.fixedNum;
	return(*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
	os << fix.toFloat();
	return (os);
}

float Fixed::toFloat( void ) const
{
	float fixed;

	fixed = this->fixedNum;
	return (fixed / fractVal);
}
int Fixed::toInt( void ) const
{
	return(this->fixedNum / fractVal);
}
