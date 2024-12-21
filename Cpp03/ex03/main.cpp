/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/21 19:59:14 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap osayi("Osayi");
    FragTrap irfan("Irfan");
    FragTrap samet("Samet");
    
    std::cout << "\n\t====== Attack ====="<<std::endl;
    irfan.attack(samet.getName()); 
    irfan.attack(samet.getName());

    samet.showInfos("FragTrap"); 
    for(int i = 0; i < 10; i++)
        osayi.attack(samet.getName());
    samet.showInfos("FragTrap"); 
    osayi.attack(samet.getName());
    samet.showInfos("FragTrap"); 
    
    std::cout << "\n\t====== Repaired ====="<<std::endl;
    osayi.beRepaired(3);
    irfan.beRepaired(10);
    
    std::cout << "\n\t====== Damage ====="<<std::endl;
    irfan.takeDamage(17);
    osayi.takeDamage(1);
    samet.takeDamage(1907);
        
    samet.attack(osayi.getName());
    
    std::cout<<"===== High Five Guys ===="<<std::endl;
    osayi.highFivesGuys();
    irfan.highFivesGuys();
    
    return (0);
}