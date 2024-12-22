/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/23 00:09:47 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dzeko("dzeko");
    FragTrap    irfan("Irfan");
    ScavTrap    tadic("Tadic");
    ClapTrap    jose("jose");
    
    std::cout << "\n\t====== Attack ====="<<std::endl;
    irfan.attack(jose.getName()); 
    dzeko.attack(jose.getName());
    tadic.attack(jose.getName());
    
    std::cout << "\n\t====== Repaired ====="<<std::endl;
    dzeko.beRepaired(3);
    irfan.beRepaired(10);
    tadic.beRepaired(20);
    
    
    std::cout << "\n\t====== Damage ====="<<std::endl;
    irfan.takeDamage(17);
    dzeko.takeDamage(1);
    jose.takeDamage(1907);
    tadic.takeDamage(10);
    
    std::cout<<std::endl;
    jose.attack(dzeko.getName());
    tadic.attack(jose.getName());
    
    std::cout<<"\n\t===== High Five Guys ===="<<std::endl;
    irfan.highFivesGuys();
    dzeko.highFivesGuys();
    
    std::cout<<"\n\t===== Guard Gate ===="<<std::endl;
    tadic.guardGate();
    dzeko.guardGate();
    
    std::cout<<"\n\t===== Who am I ===="<<std::endl;
    dzeko.whoAmI();
    return (0);
}