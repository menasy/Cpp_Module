/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:48:59 by menasy            #+#    #+#             */
/*   Updated: 2025/02/19 14:16:47 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data *data = new Data;
    data->c = 'a';
    data->i = 42;
    data->d = 42.42;
    data->b = false;
    
    std::cout << "Data size: " << sizeof(*data) << std::endl;
    uintptr_t raw = Serializer::serialize(data);
    
    data = Serializer::deserialize(raw);
    
    std::cout << "data.c = " << data->c << std::endl;
    std::cout << "data.i = " << data->i << std::endl;
    std::cout << "data.d = " << data->d << std::endl;
    std::cout << "data.b = " << data->b << std::endl;
    
    delete data;
    return 0;
}