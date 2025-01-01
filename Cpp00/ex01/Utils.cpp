/*
 ███▄ ▄███▓▓█████  ███▄    █  ▄▄▄        ██████▓██   ██▓
▓██▒▀█▀ ██▒▓█   ▀  ██ ▀█   █ ▒████▄    ▒██    ▒ ▒██  ██▒
▓██    ▓██░▒███   ▓██  ▀█ ██▒▒██  ▀█▄  ░ ▓██▄    ▒██ ██░
▒██    ▒██ ▒▓█  ▄ ▓██▒  ▐▌██▒░██▄▄▄▄██   ▒   ██▒ ░ ▐██▓░
▒██▒   ░██▒░▒████▒▒██░   ▓██░ ▓█   ▓██▒▒██████▒▒ ░ ██▒▓░
░ ▒░   ░  ░░░ ▒░ ░░ ▒░   ▒ ▒  ▒▒   ▓▒█░▒ ▒▓▒ ▒ ░  ██▒▒▒
░  ░      ░ ░ ░  ░░ ░░   ░ ▒░  ▒   ▒▒ ░░ ░▒  ░ ░▓██ ░▒░
░      ░      ░      ░   ░ ░   ░   ▒   ░  ░  ░  ▒ ▒ ░░
       ░      ░  ░         ░       ░  ░      ░  ░ ░
                                                ░ ░*/

#include "Utils.hpp"

std::string Utils::putSpace(std::string str)
{
	int len;
	int spaceCount;
	std::string showStr, shortStr;
	std::string space;

	spaceCount = 1;
	len = str.length();
	if (len > 9)
	{
		shortStr = str.substr(0, 9);
		shortStr[8] = '.';
		spaceCount += 9 - shortStr.length();
	}
	else
		spaceCount += 9 - len;
	while(spaceCount--)
		space += " ";
	if (len > 9)
		showStr = space + shortStr;
	else
		showStr = space + str;
	return (showStr);
}

bool Utils::checkChar(std::string &str, char c)
{
	int	i = -1;

	while (str[++i])
		if (str[i] != c)
			return(false);
	return(true);
}
std::string Utils::addBook(std::string quest)
{
	std::string line;

	while (true)
	{
		std::cout<<quest;
		std::getline(std::cin, line);
		if (std::cin.eof())
			std::exit(1);
		if (line.empty() || checkChar(line, ' '))
		{
			std::cout<<"\033[31mBlank value cannot be entered\033[0m"<<std::endl;
			continue ;
		}
		if (quest == "Number: " && !Utils::isNumeric(line))
		{
			std::cout << "\033[31mNumber must be numeric\033[0m" << std::endl;
			continue ;
		}
		return (line);
	}
}

bool Utils::isNumeric(std::string &str)
{
	int	i = -1;

	while (str[++i])
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

int	Utils::takeIndex(int &countPerson)
{
	int	j;

	j = -1;
	while (true)
	{
		std::cout << "\033[32mEnter index of the person to be viewed: \033[0m";
		std::cin>>j;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(IGNORE_MAX,'\n');
			std::cout<<"\033[31mInvalid input!\033[0m" << std::endl;
			if (std::cin.eof())
				exit(1);
			continue ;
		}
		else if (j > 7 || j < 0)
		{
			std::cout << "\033[31mInvalid index! Please enter a number between 0 and 7.\033[0m" << std::endl;
			std::cin.ignore(IGNORE_MAX,'\n');
			continue ;
		}
		else if (j >= countPerson)
		{
			std::cout << "\033[31mInvalid index! Maximum index is: \033[0m\033[31m" << countPerson -1 << "\033[0m" << std::endl;
			std::cin.ignore(IGNORE_MAX,'\n');
			continue ;
		}
		std::cin.ignore(IGNORE_MAX,'\n');
		return (j);
	}
}
