/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:20:50 by menasy            #+#    #+#             */
/*   Updated: 2025/02/16 22:28:35 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Data_H
# define Data_H

# include <iostream>

class Data
{
    private:
        char     c;
        int      i;
        float    f;
        double   d;
    
        bool    limC;
        bool    limI;
        bool    limF;
        bool    limD;
        
        int     sign;
    public:
        Data();
        ~Data();
        Data(const Data& obj);
        Data& operator=(const Data& obj);
        
        char	getC();
        int		getI();
        float 	getF();
        double	getD();
		
        bool 	getLimC();
        bool 	getLimI();
        bool 	getLimF();
        bool 	getLimD();
		
        int 	getSign();
        
        void	setC(char c);
        void	setI(int i);
        void	setF(float f);
        void	setD(double d);
        
        void	setLimC(bool limC);
        void	setLimI(bool limI);
        void	setLimF(bool limF);
        void	setLimD(bool limD);
        
        void 	setSign(int sign);
        
};

#endif