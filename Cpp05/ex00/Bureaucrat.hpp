/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:48:27 by menasy            #+#    #+#             */
/*   Updated: 2025/02/10 17:44:54 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>

class Bureaucrat
{
    private:
        std::string name;
        int grade;
        void checkGrade(int& grade);
    public:
        Bureaucrat(std::string name, int age);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& obj);
        Bureaucrat& operator=(const Bureaucrat& obj);

       	int	getGrade();        
        std::string	getName();
		       
        class GradeTooHighException : public std::exception{
            public:
                char const* what() const throw();
		};
        class GradeTooLowException : public std::exception{
            public:
                char const* what() const throw();
        };
};
# endif