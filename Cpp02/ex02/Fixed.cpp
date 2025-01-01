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
}
Fixed::Fixed(const int number)
{
	this->fixedNum = (number * fractVal);
}
Fixed::Fixed(const float number)
{
	this->fixedNum = roundf(number * fractVal);
}

Fixed::Fixed(const Fixed& obj)
{
	*this = obj;
}
Fixed::~Fixed()
{
}
Fixed& Fixed::operator=(const Fixed& other)
{
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
	return ((fixed / fractVal));
}

int Fixed::toInt( void ) const
{
	return(this->fixedNum / fractVal);
}


//				Comparison operators
bool Fixed::operator == (const Fixed& obj) const
{
	if (this->fixedNum == obj.fixedNum)
		return (true);
	return (false);
}

bool Fixed::operator != (const Fixed& obj) const
{
	if (this->fixedNum != obj.fixedNum)
		return (true);
	return (false);
}

bool Fixed::operator <= (const Fixed& obj) const
{
	if (this->fixedNum <= obj.fixedNum)
		return (true);
	return (false);
}

bool Fixed::operator >= (const Fixed& obj) const
{
	if (this->fixedNum >= obj.fixedNum)
		return (true);
	return (false);
}

bool Fixed::operator >  (const Fixed& obj) const
{
	if (this->fixedNum > obj.fixedNum)
		return (true);
	return (false);
}

bool Fixed::operator <  (const Fixed& obj) const
{
	if (this->fixedNum < obj.fixedNum)
		return (true);
	return (false);
}

//					Basic operators
Fixed Fixed::operator + (const Fixed& obj) const
{
	Fixed	res;

	res.fixedNum = roundf(this->fixedNum + obj.fixedNum);
	return (res);
}

Fixed Fixed::operator - (const Fixed& obj) const
{
	Fixed	res;

	res.fixedNum = roundf(this->fixedNum - obj.fixedNum);
	return (res);
}

Fixed Fixed::operator * (const Fixed& obj) const
{
	Fixed	res;

	res.fixedNum = (this->toFloat() * obj.toFloat()) * fractVal;
	return (res);
}

Fixed Fixed::operator / (const Fixed& obj) const
{
	Fixed res;

	res.fixedNum = (this->toFloat() / obj.toFloat()) * fractVal;
	return (res);
}

//				Increment (++) and Decrement(--)
Fixed Fixed::operator ++()
{
	float numFloat;

	numFloat = this->toFloat();
	numFloat += this->epsilon;
	this->fixedNum = roundf(numFloat * fractVal);
	return (*this);
}

Fixed Fixed::operator ++(int)
{
	Fixed temp(*this);
	float numFloat;

	numFloat = this->toFloat();
	numFloat += this->epsilon;
	this->fixedNum = roundf(numFloat * fractVal);
	return (temp);

}

Fixed Fixed::operator --()
{
	float numFloat;

	numFloat = this->toFloat();
	numFloat -= this->epsilon;
	this->fixedNum = roundf(numFloat * fractVal);
	return (*this);
}

Fixed Fixed::operator --(int)
{
	Fixed temp(*this);
	float numFloat;

	numFloat = this->toFloat();
	numFloat -= this->epsilon;
	this->fixedNum = roundf(numFloat * fractVal);
	return (temp);
}

//				Max - Min

Fixed& Fixed::min(Fixed &obj1, Fixed& obj2)
{
	if (obj1 < obj2)
		return (obj1);
	else
		return (obj2);
}

const Fixed& Fixed::min(const Fixed &obj1, const Fixed& obj2)
{
	if (obj1 > obj2)
		return (obj2);
	else
		return (obj1);
}

Fixed& Fixed::max(Fixed &obj1, Fixed& obj2)
{
	if (obj1 > obj2)
		return (obj1);
	else
		return (obj2);
}

const Fixed& Fixed::max(const Fixed &obj1, const Fixed& obj2)
{
	if (obj1 < obj2)
		return (obj2);
	else
		return (obj1);
}

