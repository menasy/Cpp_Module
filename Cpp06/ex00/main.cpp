/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:32:04 by menasy            #+#    #+#             */
/*   Updated: 2025/02/17 21:51:16 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int ac, char **argv)
{
    if (ac == 2)
    {
        ScalarConverter::convert(argv[1]);
    }
    else
        std::cout<< "Invalid input !" << std::endl;
    return 0;
}