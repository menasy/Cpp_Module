/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:10:24 by menasy            #+#    #+#             */
/*   Updated: 2025/02/21 21:08:03 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstring>
template <typename T>
class Array
{
	private:
		T* array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array<T>& obj);
		Array<T>& operator=(const Array<T>& obj);
		T& operator[](unsigned int index);
		unsigned int size() const;
};
# include "Array.tpp"
#endif
