/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:21:50 by menasy            #+#    #+#             */
/*   Updated: 2025/03/07 01:18:07 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	*this = other;
	return *this;
}
BitcoinExchange::~BitcoinExchange(){}

char const* BitcoinExchange::FileErrorException::what() const throw()
{
	return ("Error: could not open file.");
}
void BitcoinExchange::openFileOperation(const char *file, std::ifstream& dataFile ,std::ifstream& inputFile)
{
	inputFile.open(file);
	if (!inputFile.is_open())
	{
		inputFile.close();
		throw FileErrorException();
	}
	dataFile.open("data.csv");
	if (!dataFile.is_open())
	{
		dataFile.close();
		throw FileErrorException();
	}
}
void BitcoinExchange::fileToInputMap(std::string& str)
{
	std::string key, line,value;
	std::istringstream iss(str);
	std::getline(iss,line);
	while (std::getline(iss,line))
	{
		std::istringstream issInput(line);
		std::getline(issInput, key, '|');
		std::getline(issInput, value);
		
		key.erase(0, key.find_first_not_of(' '));
		key.erase(key.find_last_not_of(' ') + 1);
		
		value.erase(0, value.find_first_not_of(' '));
		value.erase(value.find_last_not_of(' ') + 1);
		this->inputMap.push_back(std::make_pair(key,value));
		
	}
}
void BitcoinExchange::fileToDataMap(std::string& str)
{
	std::string key, line, strValue;
	float value;
	std::istringstream iss(str);
	std::getline(iss,line);
	while (std::getline(iss,line))
	{
		std::istringstream issInput(line);
		if (std::getline(issInput, key, ',') && std::getline(issInput,strValue))
		{
			key.erase(0, key.find_first_not_of(' '));
			key.erase(key.find_last_not_of(' ') + 1);
		
			value = std::atof(strValue.c_str());
			this->dataMap.push_back(std::make_pair(key,static_cast<float>(value)));
		}
	}
}

void BitcoinExchange::displayMaps()
{
	std::cout << "\n========== Data Map ==========" << std::endl;
	for (std::vector<std::pair<std::string, float> > ::iterator it = this->dataMap.begin(); it != this->dataMap.end(); it++)
		std::cout << it->first << ": " << it->second << std::endl;
		
	std::cout << "\n========== Input Map ==========" << std::endl;
	for (std::vector<std::pair<std::string, std::string> >::iterator it = this->inputMap.begin(); it != this->inputMap.end(); it++)
		std::cout << it->first << ": " << it->second << std::endl;
	
	
}
void BitcoinExchange::readFile(std::ifstream& dataFile ,std::ifstream& inputFile)
{
	std::string fileTxt;
	std::stringstream buferData;
	std::stringstream buferInput;
	
	buferData << dataFile.rdbuf();
	buferInput << inputFile.rdbuf();
	dataFile.close();
	inputFile.close();
	
	fileTxt = buferData.str();
	fileToDataMap(fileTxt);
	fileTxt = buferInput.str();
	fileToInputMap(fileTxt);
}
bool BitcoinExchange::isValidate(const std::string& date)
{
	std::tm tm = {};
    char sep1, sep2;
    std::istringstream ss(date);
    ss >> tm.tm_year >> sep1 >> tm.tm_mon >> sep2 >> tm.tm_mday;

    if (ss.fail() || sep1 != '-' || sep2 != '-') {
        return false;
    }

    tm.tm_year -= 1900;
    tm.tm_mon -= 1;

    std::tm tmCopy = tm;
    std::mktime(&tmCopy);
	
	if (tm.tm_year == tmCopy.tm_year &&
		tm.tm_mon == tmCopy.tm_mon &&
		tm.tm_mday == tmCopy.tm_mday)
			return (true);
    return (false);
}
std::string BitcoinExchange::inputHandler(std::vector<std::pair<std::string, std::string> >::iterator itInput,
											std::vector<std::pair<std::string, float> > ::iterator& itData)
{
	std::string str;
	
	if (!isValidate(itInput->first) || itInput->second.empty() || itInput->first.length() != 10)
	{
		str = "Error: bad input => " + itInput->first;
		return str;
	}
	float num = std::atof(itInput->second.c_str());
	if (num < 0)
		str = "Error: not a positive number.";
	else if (num > 1000)
		str = "Error: too large a number.";
	else
	{
		std::stringstream iss;
		iss << itInput->first << " => " << itInput->second << " = " << (num * itData->second);
		str = iss.str();
	}
	return str;
}
void BitcoinExchange::mapHandler()
{
	std::vector<std::pair<std::string, float> > ::iterator it2;
	for (std::vector<std::pair<std::string, std::string> >::iterator it = this->inputMap.begin(); it != this->inputMap.end(); ++it)
	{
		it2 = this->dataMap.begin();
		while ((it2 != this->dataMap.end() && it2->first < it->first))
			++it2;
		if (it2->first > it->first)
			it2--;
		std::cout << inputHandler(it,it2) << std::endl;
	}
}
void BitcoinExchange::btcExchange(const char* file)
{
	std::ifstream inputFile;
	std::ifstream dataFile;
	try
	{
		openFileOperation(file, dataFile, inputFile);
		readFile(dataFile,inputFile);
		mapHandler();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
} 

