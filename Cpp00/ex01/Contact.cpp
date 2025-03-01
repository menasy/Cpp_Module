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

#include "Contact.hpp"

std::string Contact::getName()
{
	return(Contact::name);
}
std::string Contact::getSurName()
{
	return(Contact::surName);
}
std::string Contact::getNickName()
{
	return(Contact::nickName);
}
std::string Contact::getTelNum()
{
	return(Contact::telNum);
}
std::string Contact::getScret()
{
	return(Contact::darkScret);
}
void Contact::setName(std::string name)
{
	this->name = name;
}
void Contact::setSurName(std::string surName)
{
	this->surName = surName;
}
void Contact::setNickName(std::string nickName)
{
	this->nickName = nickName;
}
void Contact::setTelNum(std::string telNum)
{
	this->telNum = telNum;
}
void Contact::setScret(std::string darkScret)
{
	this->darkScret = darkScret;
}
