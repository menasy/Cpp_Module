/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:47:13 by menasy            #+#    #+#             */
/*   Updated: 2025/03/08 15:45:31 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <cmath>
# include <sstream>
# include <cstdlib>

class RPN
{
	public:
		RPN();
		RPN(const RPN &src);
		~RPN();
		RPN &operator=(const RPN &src);
		int   calculate(std::string str);

	private:
		std::stack<int> rpnStack;
		bool calcStack(const char& c);
		int mult(const int& nb1, const int& nb2);
		int div(const int& nb1, const int& nb2);
		int add(const int& nb1, const int& nb2);
		int sub(const int& nb1, const int& nb2);

		static bool checkStr(std::string& str);
		static bool strIsDigit(std::string& str);
		static int error();
};
#endif