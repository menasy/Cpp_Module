/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:10:20 by menasy            #+#    #+#             */
/*   Updated: 2025/02/22 00:53:47 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void square(int &a)
{
	a *= a;
}

void toUpper(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}
int main ()
{
	std::cout << "========== Template for int ==========" << std::endl;
	int intArry[] = {1, 2, 3, 4, 5};
	::iter(intArry, (int)sizeof(intArry)/sizeof(intArry[0]), square);
	displayArray(intArry,sizeof(intArry)/sizeof(intArry[0]));
	
	std::cout << "========== Template for string ==========" << std::endl;
	std::string stringArry[] = {"Fener", "Bahce", "1907"};
	::iter(stringArry, (int)(sizeof(stringArry)/sizeof(stringArry[0])), ::toUpper);
	displayArray(stringArry, sizeof(stringArry)/sizeof(stringArry[0]));
	
	return 0;
}