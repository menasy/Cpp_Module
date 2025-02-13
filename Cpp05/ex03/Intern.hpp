/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:28:17 by menasy            #+#    #+#             */
/*   Updated: 2025/02/13 15:23:20 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class Intern
{
    private:
        std::string toLowerStr(std::string& str);
        AForm*  createShrubberyCreation(std::string& target);
        AForm*  createRobotomyRequest(std::string& target);
        AForm*  createPresidentialPardon(std::string& target);
    public:
        Intern();

        ~Intern();
        Intern(const Intern& obj);
        Intern& operator=(const Intern& obj);
        AForm* makeForm(std::string formType, std::string formTarget);
        
        class FormNotExists : public std::exception
        {
            public:
                char const* what() const throw();
        };
};
#endif