/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:23:55 by menasy            #+#    #+#             */
/*   Updated: 2025/03/10 00:19:32 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

template <typename Container>
void PmergeMe::fillContainer(Container &container, std::deque<unsigned int> &dq)
{
	for (size_t i = 0; i < dq.size(); i++)
		container.push_back(dq[i]);
}

template <typename Container>
void PmergeMe::printContainer(const Container &container)
{
	typename Container::const_iterator it = container.begin();
	int i = 0;
	while (it != container.end())
	{
		std::cout << *it << " ";
		it++;
		i++;
		if (i == 17)
		{
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;
}
template <typename Container>
void containerMerge(Container& winner, Container& loser, int& leftOver)
{
	for (typename Container::iterator it = loser.begin(); it != loser.end(); ++it)
    {
        typename Container::iterator pos = std::lower_bound(winner.begin(), winner.end(), *it);
        winner.insert(pos, *it);
    }
    if (leftOver != -1)
    {
        typename Container::iterator pos = std::lower_bound(winner.begin(), winner.end(), leftOver);
        winner.insert(pos, leftOver);
    }
}
template <typename Container>
void PmergeMe::mergeInsertSortContainer(Container& container)
{
    if (container.size() <= 1) 
        return;
    Container winner, loser;
    int leftOver = -1;
    typename Container::iterator it = container.begin();
    while (it != container.end())
    {
        unsigned int first = *it++;
        if (it != container.end())
        {
            unsigned int second = *it++;
            if (first < second){
                winner.push_back(second);
                loser.push_back(first);
            }
            else{
                winner.push_back(first);
                loser.push_back(second);
            }
        }
        else
            leftOver = first; 
    }
    mergeInsertSortContainer(winner);
    mergeInsertSortContainer(loser);
    containerMerge(winner, loser, leftOver);
    container = winner;
}
