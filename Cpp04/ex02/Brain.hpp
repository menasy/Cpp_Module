/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/26 00:03:17 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

class Brain
{
    protected:
        std::string ideas[100];
    public:
        Brain();
        virtual ~Brain();
        Brain(const Brain& obj);
        Brain& operator=(const Brain& obj);

        void setIdeas(int index, std::string idea);
        std::string getIdeas(int index);
};

#endif