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

void	PhoneBook::add(int &i, int &countPerson)
{
	person[i].setName(Utils::addBook("Name: "));
	person[i].setSurName(Utils::addBook("Surname: "));
	person[i].setNickName(Utils::addBook("Nick Name: "));
	person[i].setTelNum(Utils::addBook("Number: "));
	person[i].setScret(Utils::addBook("Dark Scret: "));
	i++;
	if (i == 8)
		i = 0;
	if (countPerson < 8)
		countPerson++;

}

void	PhoneBook::search(int &countPerson)
{
	std::string personInfo;
	int	j;

	if (countPerson == 0)
	{
		std::cout << "\033[31mThe phonebook is empty. No contacts have been added yet.\033[0m" << std::endl;
		return ;
	}
	j = -1;
	std::cout<<"\n|    Index|      Name|   Surname|  Nickname|\n--------------------------------------------\n";;
	while (++j < countPerson)
		std::cout<<"|        "<<j<<"|"<<Utils::putSpace(person[j].getName())<<"|"<<Utils::putSpace(person[j].getSurName())<<"|"<<Utils::putSpace(person[j].getNickName())<<"|\n";
	j = Utils::takeIndex(countPerson);
	std::cout << "\033[33mName: \033[34m" << person[j].getName() << "\033[0m" << std::endl;
	std::cout << "\033[33mSurname: \033[34m" << person[j].getSurName() << "\033[0m" << std::endl;
	std::cout << "\033[33mNickname: \033[34m" << person[j].getNickName() << "\033[0m" << std::endl;
	std::cout << "\033[33mNumber: \033[34m" << person[j].getTelNum() << "\033[0m" << std::endl;
	std::cout << "\033[33mDark Secret: \033[34m" << person[j].getScret() << "\033[0m" << std::endl;


}
void	PhoneBook::exit()
{
	std::cout << "\033[31m\nProgram is terminated\033[0m" << std::endl;
	std::exit(0);
}
