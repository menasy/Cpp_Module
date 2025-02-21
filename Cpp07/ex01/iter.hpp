/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:10:24 by menasy            #+#    #+#             */
/*   Updated: 2025/02/22 00:52:35 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T> 
void iter(T *a, int lenght, void (*func)(T&))
{
	for (int i = 0; i < lenght; i++)
		func(a[i]);
}

template <typename T>
void displayArray(T *a, size_t lenght)
{
	for (size_t i = 0; i < lenght; i++)
		std::cout << a[i] << std::endl;
}

#endif
