/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:58:08 by menasy            #+#    #+#             */
/*   Updated: 2025/03/10 00:20:53 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <iterator>
# include <list>
# include <deque>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include "Utils.hpp"

class PmergeMe
{
	private:
		std::list<unsigned int> lst;
		std::deque<unsigned int> dq;
		std::deque<unsigned int> tmpDq;
		
		int checkArgv(char **argv);
		template <typename Container>
		void fillContainer(Container &container, std::deque<unsigned int> &dq);
		template <typename Container>
		void printContainer(const Container &container);
		template <typename Container>
		void mergeInsertSortContainer(Container& container);
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		~PmergeMe();
		
		int sortArgs(char **argv);

		
};

# include "PmergeMe.tpp"
#endif

