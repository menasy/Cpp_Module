/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:39:08 by menasy            #+#    #+#             */
/*   Updated: 2025/03/02 00:00:00 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0), _vec(0) {}

Span::Span(unsigned int n) : _n(n), _vec(0) {}

Span::Span(Span const &other) : _n(other._n), _vec(other._vec) {}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_n = other._n;
		_vec = other._vec;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_vec.size() >= _n)
		throw std::runtime_error("Error: Span is full");
	_vec.push_back(number);
}

int Span::shortestSpan()
{
	int vecSize = _vec.size();
	if (vecSize < 2)
		throw std::runtime_error("Error: Span is not have enough elements");
	int shortestSp = 0;
	std::sort(_vec.begin(), _vec.end());
	shortestSp = _vec[vecSize -1] - _vec[vecSize -2];
	for (int i = vecSize -1; i >= 0 ; --i)
	{
		if (i -1 >= 0 && ((_vec[i] - _vec[i -1]) < shortestSp))
			shortestSp = _vec[i] - _vec[i -1];
	}
	return shortestSp;
}

int Span::longestSpan()
{
	int vecSize = _vec.size();
	if (vecSize  < 2)
		throw std::runtime_error("Error: Span is not have enough elements");
	std::sort(_vec.begin(), _vec.end());
	int longestSp = _vec[vecSize - 1] - _vec[0];
	return longestSp;
}

void Span::printScan()
{
	std::vector<int>::iterator it = _vec.begin();
	while (it != _vec.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout<<std::endl;
}
