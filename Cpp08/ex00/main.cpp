/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:45:05 by menasy            #+#    #+#             */
/*   Updated: 2025/03/07 01:24:16 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::vector<int> vec; 
	std::list<int> lst;
	std::deque<int> deq;
	int index;
	
	std::cout << "======== Vector =========" << std::endl;
	vec.push_back(10);
	vec.push_back(7);
	vec.push_back(9);
	vec.insert(vec.begin() + 2, 3);
	displayContainer(vec);
	try
	{
		index = easyfind(vec,7);
		displayContainerIndex(vec,index);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "======== List =========" << std::endl;
	lst.push_back(47);
	lst.push_back(34);
	lst.push_back(73);
	lst.push_front(1);
	displayContainer(lst);
	try
	{
		index = easyfind(lst,73);
		displayContainerIndex(lst,index);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "======== Deque =========" << std::endl;
	deq.push_back(2);
	deq.push_back(4);
	deq.push_back(1);
	deq.push_front(5);
	displayContainer(deq);
	try
	{
		index = easyfind(deq,5);
		displayContainerIndex(deq,index);
		index = easyfind(deq,73);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
			
	return 0;
}