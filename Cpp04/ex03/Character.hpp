/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/29 00:22:28 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
	std::string name;
	AMateria **inventory;
	public:
	    Character();
        Character(std::string name);
        ~Character();
        Character(const Character& obj);
        Character& operator=(const Character& obj);
		
		std::string const & getName() const;
    	void equip(AMateria* m);
    	void unequip(int idx);
    	void use(int idx, ICharacter& target);
	
};
#endif