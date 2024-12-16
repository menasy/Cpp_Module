/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/17 00:53:10 by mehmyilm         ###   ########.fr       */
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
		static const float		epsilon = 0.00390625f;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& other);

		Fixed(const int number);
		Fixed(const float number);
		float toFloat( void ) const;
		int toInt( void ) const;

		static Fixed& min(Fixed &obj1, Fixed& obj2);
		static const Fixed& min(const Fixed & obj1, const Fixed& obj2);
		static Fixed& max(Fixed &obj1, Fixed& obj2);
		static const Fixed& max(const Fixed& obj1, const Fixed& obj2);

		bool operator == (const Fixed& obj) const;
		bool operator != (const Fixed& obj) const;
		bool operator <= (const Fixed& obj) const;
		bool operator >= (const Fixed& obj) const;
		bool operator >  (const Fixed& obj) const;
		bool operator <  (const Fixed& obj) const;

		Fixed operator + (const Fixed& obj) const;
		Fixed operator - (const Fixed& obj) const;
		Fixed operator * (const Fixed& obj) const;
		Fixed operator / (const Fixed& obj) const;

		Fixed operator ++();
		Fixed operator ++(int);
		Fixed operator --();
		Fixed operator --(int);
};
std::ostream& operator <<(std::ostream& os, const Fixed& fix);
#endif
