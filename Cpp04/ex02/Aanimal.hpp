/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/26 23:33:24 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

# include <iostream>

class Aanimal
{
    protected:
        std::string type;
    public:
        Aanimal();
        virtual ~Aanimal();
        Aanimal(const Aanimal& obj);
        Aanimal& operator=(const Aanimal& obj);
        
        std::string         getType() const;
        virtual void        makeSound() const = 0;
};

#endif