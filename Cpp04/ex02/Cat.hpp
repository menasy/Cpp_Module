/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/26 23:08:21 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

#include "Aanimal.hpp"
#include "Brain.hpp"
#include <iostream>

class   Cat : public Aanimal, public Brain
{
    private:
        Brain *brain;
    public:
        Cat();
        ~Cat();
        Cat(const Cat& obj);
        Cat& operator=(const Cat& obj);
        
        void    makeSound() const; 
};
#endif 