/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:40:44 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/02 00:38:11 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <cstdlib>


class Utils
{
	public:
		static std::string addBook(std::string quest);
		static bool checkChar(std::string &str, char c);
};

#endif
