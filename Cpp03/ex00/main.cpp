/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/19 17:37:35 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap osayi("Osayi");
    ClapTrap irfan("Irfan");
    ClapTrap samet("Samet");
   
    std::cout << "\n\t====== Attack ====="<<std::endl;
    irfan.attack(samet.getName()); 
    irfan.attack(samet.getName()); 
    for(int i = 0; i < 10; i++)
        osayi.attack(samet.getName());
    osayi.attack(samet.getName());
    
    std::cout << "\n\t====== Repaired ====="<<std::endl;
    osayi.beRepaired(3);
    irfan.beRepaired(10);
    
    std::cout << "\n\t====== Damage ====="<<std::endl;
    irfan.takeDamage(17);
    osayi.takeDamage(1);
    samet.takeDamage(1907);
        
    samet.attack(osayi.getName());
    
    return (0);
}