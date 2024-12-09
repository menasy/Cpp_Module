/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/08 17:18:47 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie*	zombieHorde( int N, std::string name )
{
	std::stringstream convIndex;
	std::string zName;

	Zombie *zHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		convIndex.str("");
		convIndex.clear();
		convIndex << (i +1);
		zName = convIndex.str() + "_" + name;
		zHorde[i].setName(zName);
	}
	return (zHorde);
}
