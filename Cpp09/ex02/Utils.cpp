/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:06:22 by menasy            #+#    #+#             */
/*   Updated: 2025/03/09 14:32:10 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

Utils::Utils(){}
Utils::~Utils(){}
Utils::Utils(Utils const &other)
{
	*this = other;
}
Utils &Utils::operator=(Utils const &other)
{
	(void)other;
	return *this;
}

int Utils::error(std::string msg)
{
	std::cerr << msg << std::endl;
	return 1;
}

void Utils::printContainerStr(const std::deque<std::string>& dq)
{
	for (size_t i = 0; i < dq.size(); i++)
		std::cout << dq[i] << " ";
	std::cout << std::endl;
}
std::deque<unsigned int> Utils::strToInt(std::deque<std::string>& strDq)
{
	std::deque<unsigned int> intDq;
	for (size_t i = 0; i < strDq.size(); i++)
		intDq.push_back(std::atoi(strDq[i].c_str()));
	return intDq;
}
std::deque<std::string> Utils::argvToContainer(char **argv)
{
	std::deque<std::string> container;
	for (size_t i = 1; argv[i]; i++)
		container.push_back(argv[i]);
	return container;
}
bool Utils::isSorted(const std::deque<unsigned int>& dq)
{
	for (size_t i = 0; i < dq.size() -1; i++)
	{
		if (dq[i] > dq[i + 1])
			return false;
	}
	return true;
}

bool Utils::isDublicate(const std::deque<unsigned int>& dq)
{
	for (size_t i = 0; i < dq.size(); i++)
	{
		for (size_t j = i + 1; j < dq.size(); j++)
		{
			if (dq[i] == dq[j])
				return true;
		}
	}
	return false;
}
bool Utils::isNumber(const std::deque<std::string>& dq)
{
	for (size_t i = 0; i < dq.size(); i++)
	{
		std::string strNum = dq[i];
		for (size_t j = 0; j < strNum.size(); j++)
		{
			if (!isdigit(strNum[j]))
				return false;
		}
	}
	return true;
}