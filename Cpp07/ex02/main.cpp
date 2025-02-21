/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:50:42 by menasy            #+#    #+#             */
/*   Updated: 2025/02/22 01:26:24 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <ctime>
#include <cstdlib>

void displayArray(Array<int> &array)
{
	for(unsigned int i = 0; i < array.size(); i++)
	{
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	}
}

void initArray(Array<int> &array, int val)
{
	for(unsigned int i = 0; i < array.size(); i++)
	{
		const int value = i*val;
		array[i] = value;
	}
}

int main ()
{
	Array<int> *numbers = new Array<int>(10);
	Array<int> *numbers2 = new Array<int>(5);
	try
	{
		initArray(*numbers,2);
		initArray(*numbers2,5);
		
		std::cout << "========== Numbers =======:" << std::endl;
		displayArray(*numbers);
		
		std::cout << "========== Numbers2 =======:" << std::endl;
		displayArray(*numbers2);
		
		std::cout << "========== Numbers2 = Numbers =======:" << std::endl;
		(*numbers2) = (*numbers);
		
		std::cout << "========== Numbers2 after coppy =======:" << std::endl;
		displayArray(*numbers2);
		(*numbers)[0] = 42;
		std::cout << "After numbers[0] = 42" << std::endl;
		std::cout << "========== Numbers2 after = 42 =======:" << std::endl;
		displayArray(*numbers2);
		std::cout << "========== Numbers =======:" << std::endl;
		displayArray(*numbers);
		
		(*numbers2)[-5] = 21;
		(*numbers)[11] = 21;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete numbers;
	delete numbers2;
	
	
	
}