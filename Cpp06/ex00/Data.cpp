/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:20:01 by menasy            #+#    #+#             */
/*   Updated: 2025/02/17 22:59:00 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
    this->limC = false;
    this->limI = false;
    this->limF = false;
    this->limD = false;

    this->pointCount = 1;
}
Data::~Data(){}
Data::Data(const Data& obj){*this = obj;}
Data& Data::operator=(const Data& obj)
{
    (void)obj;
    return(*this);
}

char	Data::getC(){return this->c;}
int		Data::getI(){return this->i;}
float 	Data::getF(){return this->f;}
double	Data::getD(){return this->d;}

bool 	Data::getLimC(){return this->limC;}
bool 	Data::getLimI(){return this->limI;}
bool 	Data::getLimF(){return this->limF;}
bool 	Data::getLimD(){return this->limD;}

int		Data::getPointCount(){return this->pointCount;}

void	Data::setC(char c){this->c = c;}
void	Data::setI(int i){this->i = i;}
void	Data::setF(float f){this->f = f;}
void	Data::setD(double d){this->d = d;}

void	Data::setLimC(bool limC){this->limC = limC;}
void	Data::setLimI(bool limI){this->limI = limI;}
void	Data::setLimF(bool limF){this->limF = limF;}
void	Data::setLimD(bool limD){this->limD = limD;}

void	Data::setPointCount(int pointCount){this->pointCount = pointCount;}


