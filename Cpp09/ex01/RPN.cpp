/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:54:12 by menasy            #+#    #+#             */
/*   Updated: 2025/03/08 17:28:02 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &src)
{
	*this = src;
}
RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
		this->rpnStack = src.rpnStack;
	return *this;
}
int RPN::error()
{
	std::cerr << "Error" << std::endl;
	return 1;
}
int RPN::mult(const int& nb1, const int& nb2)
{
	return (nb1 * nb2);
}
int RPN::div(const int& nb1, const int& nb2)
{
	if (nb2 == 0)
		throw std::invalid_argument("Error");
	return (nb1 / nb2);
}
int RPN::add(const int& nb1, const int& nb2)
{
	return (nb1 + nb2);
}
int RPN::sub(const int& nb1, const int& nb2)
{
	return (nb1 - nb2);
}

bool RPN::checkStr(std::string& str)
{
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (!isdigit(static_cast<unsigned char>(str[i])) 
			&& str[i] != '*' && str[i] != '/' 
			&& str[i] != '+' && str[i] != '-' 
			&& str[i] != ' ') 
		    return true;
	}
	return (false);
}
bool RPN::strIsDigit(std::string& str)
{
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (!isdigit(static_cast<unsigned char>(str[i])))
		{
			if ((str[i] == '-' || str[i] == '+') 
				&& (str[i +1] && isdigit(static_cast<unsigned char>(str[i + 1]))))
				continue;
			return false;
		}
	}
	return true;
}

bool RPN::calcStack(const char& c)
{

	if (this->rpnStack.size() < 2)
		return true;
	int nb1, nb2;
	std::string operation = "*/+-";
	
	nb2 = this->rpnStack.top();
	this->rpnStack.pop();
	nb1 = this->rpnStack.top();
	this->rpnStack.pop();
	int (RPN:: *ptrMember[4])(const int&, const int&) = {&RPN::mult ,&RPN::div, &RPN::add, &RPN::sub};
	for (size_t i = 0; i < operation.size(); i++)
	{
		if (operation[i] == c)
		{
			try{
				this->rpnStack.push((this->*ptrMember[i])(nb1, nb2));
				return false;
			}
			catch(const std::exception& e){
				return true;
			}
		}
	}
	return true;
}

int   RPN::calculate(std::string str)
{
	if (checkStr(str))
		return(error());
	std::string element;
	std::istringstream iss(str);
	while (std::getline(iss,element,' '))
	{
		if (element.empty())
			continue;
		else if (strIsDigit(element))
			this->rpnStack.push(std::atoi(element.c_str()));
		else if (element.size() == 1 && !isdigit(element[0]))
		{
			if (calcStack(element[0]))
				return(error());
		}
	}
	if (this->rpnStack.size() != 1)
		return(error());
	std::cout << this->rpnStack.top() << std::endl;
	return 0;
}