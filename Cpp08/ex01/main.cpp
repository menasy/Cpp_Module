/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:38:18 by menasy            #+#    #+#             */
/*   Updated: 2025/03/02 01:29:12 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>


int main()
{

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	// int vecSize = 10000;
	// Span sp(vecSize);
	// Span sp2(5);
	// Span sp3(1);
	// try
	// {
	// 	std::cout << "======== 10000 elements span ========" << std::endl;
	// 	std::vector<int> vec(vecSize);
	// 	srand(time(0));
	// 	for (int i = 0; i < vecSize; ++i)
	// 		vec.push_back(rand() % 1000);
	// 	sp.addNumber(vec.begin(), vec.end());
	// 	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	// 	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	// 	std::cout << "======== 5 elements span ========" << std::endl;
	// 	for (int i = 0; i < 5; ++i)
	// 		sp2.addNumber(rand() % 10);
	// 	sp2.printScan();
	// 	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	// 	std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	// 	// sp2.addNumber(1);
		
	// 	std::cout << "======== 1 elements span ========" << std::endl;
	// 	sp3.addNumber(1);
	// 	// sp3.addNumber(5);
	// 	std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
	// 	std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
		
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	return 0;
}