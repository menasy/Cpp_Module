/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/25 20:47:47 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.hpp"


class   WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        virtual ~WrongCat();
        WrongCat(const WrongCat& obj);
        WrongCat& operator=(const WrongCat& obj);
        
        void    makeSound() const; 
};
#endif 