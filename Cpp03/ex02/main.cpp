/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/22 22:40:36 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    FragTrap osayi("Osayi");
    FragTrap irfan("Irfan");
    ScavTrap tadic("Tadic");
    FragTrap samet("Samet");
    
    std::cout << "\n\t====== Attack ====="<<std::endl;
    irfan.attack(samet.getName()); 
    irfan.attack(samet.getName());

    tadic.attack(samet.getName());
    tadic.attack(samet.getName());
    
    samet.showInfos("FragTrap"); 
    for(int i = 0; i < 10; i++)
        osayi.attack(samet.getName());
    samet.showInfos("FragTrap"); 
    osayi.attack(samet.getName());
    samet.showInfos("FragTrap"); 
    
    std::cout << "\n\t====== Repaired ====="<<std::endl;
    osayi.beRepaired(3);
    irfan.beRepaired(10);
    tadic.beRepaired(20);
    
    
    std::cout << "\n\t====== Damage ====="<<std::endl;
    irfan.takeDamage(17);
    osayi.takeDamage(1);
    samet.takeDamage(1907);
    tadic.takeDamage(10);
    
        
    samet.attack(osayi.getName());
    tadic.attack(samet.getName());
    
    std::cout<<"\n\t===== High Five Guys ===="<<std::endl;
    osayi.highFivesGuys();
    irfan.highFivesGuys();
    
    std::cout<<"\n\t===== Guard Gate ===="<<std::endl;
    tadic.guardGate();
    
    return (0);
}