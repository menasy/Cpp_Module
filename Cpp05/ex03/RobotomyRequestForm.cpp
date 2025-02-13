/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:55:24 by menasy            #+#    #+#             */
/*   Updated: 2025/02/13 16:45:38 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
	this->target = target;
}
RobotomyRequestForm::RobotomyRequestForm(): AForm() {
    throw std::runtime_error("RobotomyRequestForm needs a target.");
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj): AForm(obj)
{
    *this = obj;
}
    
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) 
{

    if (this == &obj)
        return *this;
    this->target = obj.target;
    return(*this);
}

//Override
void RobotomyRequestForm::executeHandler() const
{
    std::srand(std::time(0));
    
    std::cout << "\033[1;33m* Drilling noises *\033[0m" << std::endl;
    if (std::rand() % 2 == 1)
        std::cout << "\033[1;33m" << this->target << " has been robotomized successfully (50% chance).\033[0m" << std::endl;
    else
        std::cout << "\033[1;33mRobotomy failed for " << this->target << ".\033[0m" << std::endl;

}     
