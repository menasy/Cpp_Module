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

#include "PhoneBook.hpp"

int main()
{
	std::string command;
	PhoneBook phnBook;
	static int i = 0;
	int countPerson = 0;

	while (true)
	{
		std::cout<<"1-)ADD\n2-)SEARCH\n3-)EXIT\nEnter command: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			std::exit(1);
		else if (command == "EXIT")
			phnBook.exit();
		else if (command == "ADD")
			phnBook.add(i, countPerson);
		else if (command == "SEARCH")
			phnBook.search(countPerson);
		else
			std::cout << "\033[31mInvalid Command !\033[0m" << std::endl;
	}
	return (0);
}
