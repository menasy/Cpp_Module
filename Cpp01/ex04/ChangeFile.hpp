/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChangeFile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/09 22:38:51 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANGEFILE_H
#define CHANGEFILE_H

#include <iostream>
#include <fstream>

class ChangeFile
{
	private:
		std::ofstream	outFile;
		std::ifstream	inFile;
		std::string		fileName;
		std::string		firstStr;
		std::string		secStr;
		int				openFiles();
		std::string		changeText(std::string &line);
	public:
	ChangeFile(std::string firstStr, std::string secStr, std::string fileName);
	int					replaceFile();

};

#endif
