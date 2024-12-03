/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:40:44 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/03 00:41:42 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H
#include "PhoneBook.hpp"

class Utils
{
	public:
		static std::string	addBook(std::string quest);
		static bool			checkChar(std::string &str, char c);
		static std::string	putSpace(std::string str);
		static int			takeIndex(int &i);
		static bool			isNumeric(std::string &str);
};

#endif
