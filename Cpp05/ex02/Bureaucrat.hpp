/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:48:27 by menasy            #+#    #+#             */
/*   Updated: 2025/02/12 18:29:34 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
        void setGrade(int& grade);
    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& obj);
        Bureaucrat& operator=(const Bureaucrat& obj);
        

       	const int&	getGrade() const;        
        const std::string&	getName() const;
		void IncreaseGrade();      
        void reductGrade();   

        void signForm(AForm& form);
        void executeForm(AForm const & form) const;   
        class GradeTooHighException : public std::exception{
            public:
                char const* what() const throw();
		};
        class GradeTooLowException : public std::exception{
            public:
                char const* what() const throw();
        };
};
std::ostream& operator << (std::ostream& os, const Bureaucrat& obj);
# endif