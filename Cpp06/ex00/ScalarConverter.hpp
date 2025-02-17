/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:20:50 by menasy            #+#    #+#             */
/*   Updated: 2025/02/18 00:00:31 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_H
# define ScalarConverter_H

# include <iostream>
# include <limits>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include "Data.hpp"

class ScalarConverter
{
    private:
        static Data data;
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& obj);
        ScalarConverter& operator=(const ScalarConverter& obj);

        static void displayChar(const int& c);
        static void displayInt();
        static void displayFloat();
        static void displayDouble();
        static void displayData();
        static void convertOne(const std::string& literal);
        static void checkLimits(const std::string& literal);
        static void convertNum(const std::string& literal);
        static void handlePseudoLiteral(const std::string& literal);

        
    public:
        static void convert(const std::string &literal);

};

#endif