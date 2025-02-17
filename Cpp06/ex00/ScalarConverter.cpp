/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:27:24 by menasy            #+#    #+#             */
/*   Updated: 2025/02/18 00:29:06 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

Data ScalarConverter::data = Data();

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& obj){*this = obj;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj){
    (void)obj;
    return *this;}


void ScalarConverter::displayChar(const int& c)
{
    if (data.getLimC() || (c < 0 || c > 127))
        std::cout << "Char: impossible " << std::endl;
    else if (!data.getLimC() && isprint(c))
        std::cout << "Char: " << "'" << static_cast<char>(c) << "'" << std::endl;
    else
        std::cout << "Char: Non displayable " << std::endl;

}

void ScalarConverter::displayInt()
{
    if (data.getLimI())
        std::cout << "Int: impossible " << std::endl;
    else
        std::cout << "int: " << data.getI() << std::endl;
}

void ScalarConverter::displayDouble()
{
    std::cout << std::fixed << std::setprecision(data.getPointCount());
    if (data.getLimD())
        std::cout << "Double: impossible " << std::endl;
    else
        std::cout << "Double: " << data.getD() << std::endl;

}
void ScalarConverter::displayFloat()
{
    std::cout << std::fixed << std::setprecision(data.getPointCount());
    if (data.getLimF())
        std::cout << "Float: impossible " << std::endl;
    else
        std::cout << "Float: " << data.getF() << "f" << std::endl;

}

void ScalarConverter::displayData()
{
    displayChar(data.getI());
    displayInt();
    displayFloat();
    displayDouble();
    
}

void ScalarConverter::convertOne(const std::string& literal)
{
 
    if (!isdigit(literal[0]))
    {
        data.setC(static_cast<char>(literal[0]));
        data.setI(static_cast<int>(data.getC()));
        data.setF(static_cast<float>(data.getC())); 
        data.setD(static_cast<double>(data.getC()));
        displayData();
    }
    else
    {
        data.setI(std::atoi(literal.c_str()));
        data.setF(static_cast<float>(data.getI()));
        data.setD(static_cast<double>(data.getI()));
        displayData();
    } 
}
static int lenPoint(const std::string& str)
{
	int point;
	int pointCount = 1;
	
	point = str.find_first_of(".");
	if (point == (int)(str.length() -1) || point == (int)std::string::npos)
		return pointCount;
	for (int i = 0; i < point; i++)
	{
		if (!isdigit(str[i]))
			return pointCount;
	}
	if (!isdigit(str[point + 1]))
		return pointCount;
	else
		pointCount--;
	for (int i = point + 1; i < (int)str.length(); i++)
	{
		if (isdigit(str[i]))
			pointCount++;
		else
			break;
	}
	return pointCount;
}
void ScalarConverter::checkLimits(const std::string& literal)
{
    std::istringstream iss(literal);
    long int intNum;
   	long double doubleNum;
	
	iss >> doubleNum;
	intNum = static_cast<long int>(doubleNum);
	   
	if (intNum > 0)
		data.setPointCount(lenPoint(literal));
	else
		data.setPointCount(lenPoint(literal.substr(1)));
	
    if (intNum > std::numeric_limits<int>::max() || intNum < std::numeric_limits<int>::min())
    {
        data.setLimI(true);
        data.setLimC(true);
    }
    if (doubleNum > std::numeric_limits<double>::max() || doubleNum < -std::numeric_limits<double>::max())
        data.setLimD(true);	
    if (doubleNum > std::numeric_limits<float>::max() || doubleNum < -std::numeric_limits<float>::max())
        data.setLimF(true);
}
void ScalarConverter::convertNum(const std::string& numStr)
{
    	if (!data.getLimD())
        	data.setD(std::atof(numStr.c_str()));
        if(!data.getI())
            data.setI(static_cast<int>(data.getD()));
        if (!data.getC())
            data.setC(static_cast<char>(data.getI()));
        if (!data.getF())
            data.setF(static_cast<float>(data.getD()));
        displayData();
}
void  ScalarConverter::handlePseudoLiteral(const std::string& literal)
{
	if (literal == "nan" || literal == "nanf")
	{
		data.setD(std::numeric_limits<double>::quiet_NaN());
		data.setF(std::numeric_limits<float>::quiet_NaN());
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		data.setD(std::numeric_limits<double>::infinity());
		data.setF(std::numeric_limits<float>::infinity());
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		data.setD(-std::numeric_limits<double>::infinity());
		data.setF(-std::numeric_limits<float>::infinity());
	}
	else
	{
		data.setLimF(true);
		data.setLimD(true);
	}
	
}
void ScalarConverter::convert(const std::string& literal)
{
    
    if (literal.length() == 1)
    {
        convertOne(literal);
        return;
    }
    else if ((literal[0] == '-' && isdigit(literal[1])) || isdigit(literal[0]))
        checkLimits(literal);
    else
    {
        data.setLimC(true);
        data.setLimI(true);
		handlePseudoLiteral(literal);
        displayData();
        return;
    }
    convertNum(literal);
   
}