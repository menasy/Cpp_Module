/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChangeFile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/09 22:39:00 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ChangeFile.hpp"

ChangeFile::ChangeFile(std::string firstStr, std::string secStr, std::string fileName)
{
	this->firstStr = firstStr;
	this->secStr = secStr;
	this->fileName = fileName;
}
int	ChangeFile::openFiles()
{
	std::string newFile;
	size_t	indexFile;

	this->inFile.open(fileName.c_str());
	if (!this->inFile.is_open())
	{
		std::cout<< "File not found\n";
		this->inFile.close();
		return(-1);
	}
	indexFile = this->fileName.find_last_of('.');
	if (indexFile == std::string::npos)
		newFile = this->fileName + ".replace";
	else
		newFile = this->fileName.substr(0,indexFile) + ".replace";
	this->outFile.open(newFile.c_str(), std::ofstream::in | std::ofstream::out | std::ofstream::trunc);
	if (!this->outFile.is_open())
	{
		std::cout<< "File can't opened";
		this->outFile.close();
		return(-1);
	}
	return (0);
}
std::string	ChangeFile::changeText(std::string &line)
{
	size_t i, lenFirst;
	std::string newLine, dest, tmp, srcLine;

	lenFirst = this->firstStr.length();
	srcLine = line;
	while (true)
	{
		i = line.find(this->firstStr);
		if (i == std::string::npos)
		{
			if (srcLine != line)
			{
				newLine = line.substr(0, line.length());
				dest.append(newLine);
			}
			else
				dest = srcLine;
			break ;
		}
		newLine = line.substr(0, i) + this->secStr;
		line = line.substr(i + lenFirst, line.length());
		dest.append(newLine);
	}
	return (dest);
}
int ChangeFile::replaceFile()
{
	std::string line;
	std::string newLine;
	if (openFiles() == -1)
		return(-1);
	while (!this->inFile.eof())
	{
		std::getline(this->inFile,line);
		newLine = changeText(line);
		this->outFile << newLine <<std::endl;
	}
	this->inFile.close();
	this->outFile.close();
	return (0);
}
