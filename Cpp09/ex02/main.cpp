/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:11:14 by menasy            #+#    #+#             */
/*   Updated: 2025/03/10 00:21:44 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr<< "Error: Invalid number of arguments !" << std::endl;
		return 1;
	}
	PmergeMe pmergeMe;
	return pmergeMe.sortArgs(argv);
}