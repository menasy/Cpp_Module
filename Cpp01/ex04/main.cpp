/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/09 22:48:53 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ChangeFile.hpp"

static int	error(std::string str)
{
	std::cout << "\033[31m" << str << "\033[0m" << std::endl;
	return (1);
}

int main(int ac, char **argv)
{
	std::string file, firstStr, lastStr;

	if (ac != 4)
		return (error("Error: Invalid arguments !"));
	file = argv[1];
	firstStr = argv[2];
	lastStr = argv[3];
	if (file.empty() || firstStr.empty() || lastStr.empty())
		error("Error: Empty arguments !");

	ChangeFile file1(firstStr,lastStr, file);
	if (file1.replaceFile() == -1)
		return(error("Error: File error !"));
	return(0);
}
