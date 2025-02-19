/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:21:39 by menasy            #+#    #+#             */
/*   Updated: 2025/02/19 17:32:32 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>


class A;
class B;
class C;

class Base
{
    public:
        virtual ~Base();
        Base * generate(void);
        void identify(Base* p);
        void identify(Base& p);
};

#endif