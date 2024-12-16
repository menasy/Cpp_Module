/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/15 16:25:46 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
	private:
		int					fixedNum;
		static const int 	fractNum = 8;
	public:
		Fixed();
		Fixed(const Fixed& obj);
		~Fixed();
		Fixed& operator=(const Fixed& other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
#endif
