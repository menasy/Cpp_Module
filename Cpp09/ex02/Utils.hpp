/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:05:33 by menasy            #+#    #+#             */
/*   Updated: 2025/03/09 14:39:56 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <iterator>
# include <list>
# include <deque>
# include <cstdlib>

class Utils
{
	public:
		Utils();
		Utils(Utils const &other);
		Utils &operator=(Utils const &other);
		~Utils();

		static int error(std::string msg);
		static void printContainerStr(const std::deque<std::string>& dq);
		static std::deque<unsigned int> strToInt(std::deque<std::string>& strDq);
		static std::deque<std::string> argvToContainer(char **argv);
		static bool isSorted(const std::deque<unsigned int>& dq);
		static bool isDublicate(const std::deque<unsigned int>& dq);
		static bool isNumber(const std::deque<std::string>& dq);
		
};

#endif