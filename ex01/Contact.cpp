/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:16:06 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/09/19 22:27:15 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::ft_get_name()const
{
	return (this->Name);
}

std::string Contact::ft_get_surName()const
{
	return (this->SurName);
}

std::string Contact::ft_get_nickName()const
{
	return (this->NickName);
}

std::string Contact::ft_get_darkSecret()const
{
	return (this->DarkSecret);
}

int Contact::ft_get_telNo()const
{
	return (this->TelNo);
}

void Contact::ft_set_name(std::string name)
{
	this->Name = name;
}

void Contact::ft_set_surName(std::string surName)
{
	this->SurName = surName;
}

void Contact::ft_set_nickName(std::string nickName)
{
	this->NickName = nickName;
}

void Contact::ft_set_darkSecret(std::string darkSecret)
{
	this->DarkSecret = darkSecret;
}

void Contact::ft_set_telNo(int telNo)
{
	this->TelNo = telNo;
}
