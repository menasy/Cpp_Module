/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:10:20 by menasy            #+#    #+#             */
/*   Updated: 2025/02/22 00:26:40 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int square(int &a)
{
	return (a * a);
}

std::string toUpper(std::string &str)
{
	for (int i = 0; str[i]; i++)
		str[i] = std::toupper(str[i]);
	return str;
}
int main ()
{
	std::cout << "========== Template for int ==========" << std::endl;
	int intArry[] = {1, 2, 3, 4, 5};
	::iter(intArry,sizeof(intArry)/sizeof(intArry[0]),square);
	displayArray(intArry,sizeof(intArry)/sizeof(intArry[0]));
	
	std::cout << "========== Template for string ==========" << std::endl;
	std::string stringArry[] = {"Fener", "Bahçe", "1907"};
	::iter(stringArry, sizeof(stringArry)/sizeof(stringArry[0]), ::toUpper);
	displayArray(stringArry, sizeof(stringArry)/sizeof(stringArry[0]));
	
	return 0;
}