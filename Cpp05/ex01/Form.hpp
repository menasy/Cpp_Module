/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:48:27 by menasy            #+#    #+#             */
/*   Updated: 2025/02/11 22:48:20 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    public:
        Form();
        Form(std::string const name, int signGrade);
        ~Form();
        Form(const Form& obj);
        Form& operator=(const Form& obj);
        

       	const int&	getSignGrade() const;        
        const std::string&	getName() const;
        const bool& getIsSigned() const;
       	const int&	getExecGrade() const;        
        
        
        void beSigned(const Bureaucrat& obj);      
        class GradeTooHighException : public std::exception{
            public:
                char const* what() const throw();
		};
        class GradeTooLowException : public std::exception{
            public:
                char const* what() const throw();
        };
};
std::ostream& operator << (std::ostream& os, const Form& obj);
# endif