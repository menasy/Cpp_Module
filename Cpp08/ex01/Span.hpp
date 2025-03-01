/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:37:14 by menasy            #+#    #+#             */
/*   Updated: 2025/03/01 23:59:51 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <iterator>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _vec;
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		template <typename Container>
		void addNumber(Container begin, Container end)
		{
			if ((_vec.size() + std::distance(begin, end)) > _n)
				throw std::runtime_error("Error: Span is full");
			_vec.insert(_vec.end(), begin, end);
		}
		
		template <typename Container>
		void displayContainer(Container& container)
		{
			typename Container::iterator it = container.begin();
			while (it != container.end())
			{
				std::cout << *it << " ";
				it++;
			}
			std::cout<<std::endl;
		}
		void printScan();
};



#endif