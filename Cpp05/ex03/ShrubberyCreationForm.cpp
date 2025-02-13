/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:55:24 by menasy            #+#    #+#             */
/*   Updated: 2025/02/12 23:38:25 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
}
ShrubberyCreationForm::ShrubberyCreationForm(): AForm() {
    throw std::runtime_error("ShrubberyCreationForm needs a target.");
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj): AForm(obj)
{
    *this = obj;
}
    
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) 
{

    if (this == &obj)
        return *this;
    this->target = obj.target;
    return(*this);
}

//Override
void ShrubberyCreationForm::executeHandler() const
{
    std::string newTarget = this->target + "_shrubbery";
    std::ofstream file(newTarget.c_str());

    if (!file)
        std::cout << "Error: Could not create file!" << std::endl;
    
    file << "..................................................\n";
    file << "........................FB........................\n";
    file << "......................FBFB........................\n";
    file << ".....................-FBFBFB:......................\n";
    file << ".....................-FBFBFB:......................\n";
    file << ".....................FBFBFBFB.......................\n";
    file << ".....................FBFB*FB........................\n";
    file << "...........FB.......:FBFBF........=FB............\n";
    file << "............FBFB.....FBFBF.....=FFFF.............\n";
    file << "............=FFFFB+...:*FBFB....-FBFB:.............\n";
    file << "........:FB:......FB:..FB-..:FB:......-F..........\n";
    file << ".........-FBFB+:.....FB-*:FB:....-FBFBF...........\n";
    file << ".........=FB*FBFB:....FB=....:FBFB*FB...........\n";
    file << "...........=FBFB*FB+:...*...-FB*FBFB-............\n";
    file << "............-FBFBFB+:..*..=FB*FBFBF..............\n";
    file << ".............-=FBFBFB+=:*-FBFBF=--...............\n";
    file << ".................::....FB-....::.................\n";
    file << "........................FB..........................\n";
    file << "........................FB..........................\n";
    file << "........................FB..........................\n";
    file << "..................................................\n";
    
    std::cout << "\033[1;33mFile is created: " << newTarget << "\033[0m" << std::endl;

    file.close(); 

}     
