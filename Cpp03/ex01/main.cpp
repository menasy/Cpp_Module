/*
 ███▄ ▄███▓▓█████  ███▄    █  ▄▄▄        ██████▓██   ██▓
▓██▒▀█▀ ██▒▓█   ▀  ██ ▀█   █ ▒████▄    ▒██    ▒ ▒██  ██▒
▓██    ▓██░▒███   ▓██  ▀█ ██▒▒██  ▀█▄  ░ ▓██▄    ▒██ ██░
▒██    ▒██ ▒▓█  ▄ ▓██▒  ▐▌██▒░██▄▄▄▄██   ▒   ██▒ ░ ▐██▓░
▒██▒   ░██▒░▒████▒▒██░   ▓██░ ▓█   ▓██▒▒██████▒▒ ░ ██▒▓░
░ ▒░   ░  ░░░ ▒░ ░░ ▒░   ▒ ▒  ▒▒   ▓▒█░▒ ▒▓▒ ▒ ░  ██▒▒▒
░  ░      ░ ░ ░  ░░ ░░   ░ ▒░  ▒   ▒▒ ░░ ░▒  ░ ░▓██ ░▒░
░      ░      ░      ░   ░ ░   ░   ▒   ░  ░  ░  ▒ ▒ ░░
       ░      ░  ░         ░       ░  ░      ░  ░ ░
                                                ░ ░*/

#include "ScavTrap.hpp"

int main()
{
    ScavTrap osayi("Osayi");
    ScavTrap irfan("Irfan");
    ClapTrap samet("Samet");
    
    std::cout << "\n\t====== Attack ====="<<std::endl;
    irfan.attack(samet.getName()); 
    irfan.attack(samet.getName());

    samet.showInfos("ScavTrap"); 
    for(int i = 0; i < 10; i++)
        osayi.attack(samet.getName());
    samet.showInfos("ScavTrap"); 
    osayi.attack(samet.getName());
    samet.showInfos("ScavTrap"); 
    
    std::cout << "\n\t====== Repaired ====="<<std::endl;
    osayi.beRepaired(3);
    irfan.beRepaired(10);
    
    std::cout << "\n\t====== Damage ====="<<std::endl;
    irfan.takeDamage(17);
    osayi.takeDamage(1);
    samet.takeDamage(1907);
        
    samet.attack(osayi.getName());
    
    std::cout<<"\n\t===== Guard Gate ===="<<std::endl;
    osayi.guardGate();
    irfan.guardGate();
    
    return (0);
}