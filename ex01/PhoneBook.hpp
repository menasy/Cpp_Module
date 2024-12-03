/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:39 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/03 15:18:58 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "Utils.hpp"

#define IGNORE_MAX 10000000

class PhoneBook
{
	private:
		Contact		person[8];
	public:
		void add(int &i, int &countPerson);
		void search(int &countPerson);
		void exit();

};
#endif
