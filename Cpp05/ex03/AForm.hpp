/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:48:27 by menasy            #+#    #+#             */
/*   Updated: 2025/02/13 00:06:38 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    public:
        AForm();
        AForm(std::string const name, int signGrade, int execGrade);
        virtual ~AForm();
        AForm(const AForm& obj);
        AForm& operator=(const AForm& obj);

        const int&	getSignGrade() const;        
        const std::string&	getName() const;
        const bool& getIsSigned() const;
       	const int&	getExecGrade() const;

        void beSigned(const Bureaucrat& obj);
        void beExecute(const Bureaucrat& obj) const;  
        void execute(Bureaucrat const & executor) const;
        virtual void executeHandler() const  = 0;   
          
        class GradeTooHighException : public std::exception{
            public:
                char const* what() const throw();
		};
        class GradeTooLowException : public std::exception{
            public:
                char const* what() const throw();
        }; 
        class FormIsNotSignedException : public std::exception{
            public:
                char const* what() const throw();
        };       
};
std::ostream& operator << (std::ostream& os, const AForm& obj);
#endif
