/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:44:36 by menasy            #+#    #+#             */
/*   Updated: 2025/02/21 22:46:35 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->_size = 0;
	this->array = NULL;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	try
	{
		this->array = new T[n];
		this->_size = n;
		for (unsigned int i = 0; i < n; i++)
    		this->array[i] = T();
	}
	catch(const std::exception& e)
	{
		std::cerr <<"Memory allocation failed: " << e.what() << '\n';
	}
	
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->array;
}

template <typename T>
Array<T>::Array(const Array<T>& obj)
{
	this->_size = obj._size;
    this->array = new T[this->_size];
    for (unsigned int i = 0; i < this->_size; i++)
        this->array[i] = obj.array[i]; 
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj)
{
	if (this == &obj)
		return *this;
	if (this->array != NULL)
		delete[] this->array;
	this->_size = obj._size;
	this->array = new T[this->_size];
	for (unsigned int i = 0; i < obj._size; i++)
		this->array[i] = obj.array[i];
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (this->array == NULL || index >= this->_size)
		throw std::exception();
	return this->array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return(_size);
}
