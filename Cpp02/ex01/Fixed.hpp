/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/17 00:56:26 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <math.h>

class Fixed
{
	private:
		int						fixedNum;
		static const int		fractNum = 8;
		static const int		fractVal =  (1 << Fixed::fractNum);
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& other);

		Fixed(const int number);
		Fixed(const float number);
		float toFloat( void ) const;
		int toInt( void ) const;


};
std::ostream& operator <<(std::ostream& os, const Fixed& fix);

#endif
