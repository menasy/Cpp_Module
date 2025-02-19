/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:20:50 by menasy            #+#    #+#             */
/*   Updated: 2025/02/19 14:13:06 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Serializer_H
# define Serializer_H

# include <iostream>
# include <stdint.h>

struct Data
{
    char    c;
    int     i;
    double  d;
    bool    b;
};

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer& obj);
        Serializer& operator=(const Serializer& obj);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif