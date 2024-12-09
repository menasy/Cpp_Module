/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/08 15:13:32 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	Zombie::setName(name);
}
Zombie::~Zombie()
{
	std::cout<<this->name<<": is destroyed !"<<std::endl;
}
void	Zombie::announce(void)
{
	std::cout<<Zombie::getName()<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

std::string	Zombie::getName()
{
	return (this->name);
}
void	Zombie::setName(std::string name)
{
	this->name = name;
}
