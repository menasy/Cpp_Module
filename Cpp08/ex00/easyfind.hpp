/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:30:44 by menasy            #+#    #+#             */
/*   Updated: 2025/03/01 17:08:55 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <iterator>

template <typename Container>
int easyfind(Container &container, int value)
{
	typename Container::iterator it = container.begin();
	int index = 0;
	while (it != container.end())
	{
		if (*it == value)
			return(index);
		it++;
		index++;
	}
	throw std::exception();
}

template <typename Container>
void displayContainer(Container& container)
{
	typename Container::iterator it = container.begin();
	while (it != container.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout<<std::endl;
	
}
template <typename Container>
void displayContainerIndex(Container& container, int& index)
{
	if (index > (int)container.size() || index < 0)
		throw std::exception();
	typename Container::iterator it = container.begin();
	for (int i = 0; i < index; i++)
		it++;
	std::cout<< "[" << index << "] = " << *it << std::endl;
}
#endif