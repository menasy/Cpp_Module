/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:55:24 by menasy            #+#    #+#             */
/*   Updated: 2025/02/12 23:35:22 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5)
{
	this->target = target;
}
PresidentialPardonForm::PresidentialPardonForm(): AForm() {
    throw std::runtime_error("PresidentialPardonForm needs a target.");
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj): AForm(obj)
{
    *this = obj;
}
    
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) 
{

    if (this == &obj)
        return *this;
    this->target = obj.target;
    return(*this);
}

//Override
void PresidentialPardonForm::executeHandler() const
{
    std::cout << "\033[1;33m" << this->target << " has been pardoned by Zaphod Beeblebrox." << "\033[0m" << std::endl;

}     
