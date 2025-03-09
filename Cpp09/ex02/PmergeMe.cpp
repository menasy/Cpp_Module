/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:17:16 by menasy            #+#    #+#             */
/*   Updated: 2025/03/09 23:59:01 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(PmergeMe const &other)
{
	*this = other;
}
PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	if (this != &other)
	{
		this->lst = other.lst;
		this->dq = other.dq;
	}
	return *this;
}

int PmergeMe::checkArgv(char **argv)
{
	std::deque<std::string> strContainer = Utils::argvToContainer(argv);
	if (!Utils::isNumber(strContainer))
		return Utils::error("Error: Invalid argument !");
	this->tmpDq = Utils::strToInt(strContainer);
	if (Utils::isSorted(this->tmpDq))
		return Utils::error("Error: Elements are already sorted !");
	if (Utils::isDublicate(this->tmpDq))
		return Utils::error("Error: Duplicate elements !");
	return (0);
}

int PmergeMe::sortArgs(char **argv)
{
	if (this->checkArgv(argv))
		return 1;
	clock_t start, end;
	
	start = clock();
	fillContainer(this->lst, this->tmpDq);
	mergeInsertSortContainer(this->lst);
	end = clock();
	double diffLst = double(end - start) / CLOCKS_PER_SEC * 1000000;
	
	start = clock();
	fillContainer(this->dq, this->tmpDq);
	mergeInsertSortContainer(this->dq);
	end = clock();
	double diffDq = double(end - start) / CLOCKS_PER_SEC * 1000000;
	
	std::cout << "Before:\t";
	printContainer(this->tmpDq);

	std::cout << "After:\t";
	printContainer(this->dq);
	
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Time to process a range of	" << this->lst.size() 
			<< " elements with std::list : " << diffLst << " us" << std::endl;
	std::cout << "Time to process a range of	" << this->dq.size() 
			<< " elements with std::deque : " << diffDq << " us" << std::endl;
	return 0;
}