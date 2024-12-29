/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/29 16:42:44 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MATERIASOURCE_H
# define MATERIASOURCE_H

# include "IMateriaSource.hpp"
# include <iostream>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *mInventory[4];
		void	deleteInventory();
		void   initInventory();
	public:
		MateriaSource();
		~MateriaSource();
        MateriaSource(MateriaSource const &obj);
        MateriaSource &operator=(MateriaSource const &obj);
		
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif