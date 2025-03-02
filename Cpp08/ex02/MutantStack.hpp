/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:14:21 by menasy            #+#    #+#             */
/*   Updated: 2025/03/02 16:40:58 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>
# include <algorithm>
# include <deque>
template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const &src);
		~MutantStack();
		MutantStack &operator=(MutantStack const &rhs);
		typedef typename std::deque<T>::iterator iterator;
		iterator begin();
		iterator end();
		void	push(const T& val);
		T&	top();
		void	pop();
};
# include "MutantStack.tpp"

#endif