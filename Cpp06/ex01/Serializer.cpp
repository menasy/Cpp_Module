/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:50:06 by menasy            #+#    #+#             */
/*   Updated: 2025/02/19 14:10:23 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::~Serializer(){}
Serializer::Serializer(const Serializer& obj){*this = obj;}
Serializer& Serializer::operator=(const Serializer& obj){(void) obj; return *this;}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t  raw = reinterpret_cast<uintptr_t>(ptr);
    return raw;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *ptr = reinterpret_cast<Data*>(raw);
    return ptr;
}
