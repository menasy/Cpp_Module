/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/30 00:48:15 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter* me = new Character("me");
		
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		ICharacter* bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(1, *bob);
		
		delete me;
		delete bob;
		delete src;
	}

	{
		Character ferdi("ferdi");
		Character arda("arda");

		ICharacter *oster =  new Character("oster");
		AMateria *a = new Ice();
		AMateria *b = new Cure();
		AMateria *c = new Cure();
		
		ferdi = arda;
		
		ferdi.unequip(5);
		arda.unequip(-1);

		ferdi.equip(a);
		ferdi.equip(b);
		ferdi.equip(c);
		ferdi.equip(a);
		ferdi.equip(b);
		
		std::cout<< "\n====== Full Inventory ======" << std::endl;
		for (int i = 0; i < 4; i++)
			ferdi.use(i, *oster);
			
		ferdi.unequip(2);
		ferdi.unequip(1);
		ferdi.unequip(3);
		ferdi.unequip(4);
		
		std::cout<< "\n====== After Unequip Inventory ======" << std::endl;
		for (int i = 0; i < 4; i++)
			ferdi.use(i,*oster);
			
		delete	a;
		delete	b;
		delete	c;
		delete oster;
	}

	return (0);
}