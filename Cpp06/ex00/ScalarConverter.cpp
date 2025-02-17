/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:27:24 by menasy            #+#    #+#             */
/*   Updated: 2025/02/17 18:18:43 by menasy           ###   ########.fr       */
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
    std::cout << std::fixed << std::setprecision(2);
    if (data.getLimD())
        std::cout << "Double: impossible " << std::endl;
    else
        std::cout << "Double: " << data.getD() << std::endl;

}
void ScalarConverter::displayFloat()
{
    std::cout << std::fixed << std::setprecision(2);
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

void ScalarConverter::checkLimits(const std::string& literal)
{
    std::istringstream iss(literal);
    long int intNum;
    long double doubleNum;
    
    iss >> doubleNum;
    intNum = static_cast<long int>(doubleNum);

    if (intNum > std::numeric_limits<int>::max() || intNum < std::numeric_limits<int>::min())
    {
        data.setLimI(true);
        data.setLimC(true);
    }
    if (doubleNum > std::numeric_limits<double>::max() || doubleNum < std::numeric_limits<double>::min())
        data.setLimD(true);
    if (doubleNum > std::numeric_limits<float>::max() || doubleNum < std::numeric_limits<float>::min())
        data.setLimF(true);
  
}
void ScalarConverter::convertNum(const std::string& numStr)
{
    if (!data.getLimD())
    {
        data.setD(std::atof(numStr.c_str()));
        if (data.getSign() == -1)
            data.setD(data.getD() * -1);
        data.setI(static_cast<int>(data.getD()));
        data.setC(static_cast<char>(data.getI()));
        data.setF(static_cast<float>(data.getD()));
    }
    displayData();
}


void ScalarConverter::convert(const std::string& literal)
{
    std::string numStr = literal;  
    
    if (literal.length() == 1)
    {
        convertOne(literal);
        return;
    }
    else if (literal[0] == '-' && isdigit(literal[1]))
    {
        data.setSign(-1);
        numStr = literal.substr(1);
        checkLimits(numStr);
    }
    else if (isdigit(literal[0]))
        checkLimits(literal);
    else
    {
        data.setLimC(true);
        data.setLimI(true);
        data.setLimF(true);
        data.setLimD(true);
        displayData();
        return;
    }
    convertNum(numStr);
    

   
}