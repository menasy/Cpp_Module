/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:02:22 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/03 14:56:42 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <cstdlib>

class	Contact
{
	private:
		std::string	name;
		std::string	surName;
		std::string	nickName;
		std::string	telNum;
		std::string	darkScret;
	public:
		std::string getName();
		std::string getSurName();
		std::string getNickName();
		std::string getTelNum();
		std::string getScret();

		void setName(std::string name);
		void setSurName(std::string surName);
		void setNickName(std::string nickName);
		void setTelNum(std::string telNum);
		void setScret(std::string darkScret);

};

#endif
