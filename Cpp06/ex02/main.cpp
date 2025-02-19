/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:16:08 by menasy            #+#    #+#             */
/*   Updated: 2025/02/19 18:13:38 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    Base base;
    Base *ptrBase = base.generate();
    Base &rfBase = *ptrBase;
    
    ptrBase->identify(ptrBase);
    ptrBase->identify(base);
    ptrBase->identify(rfBase);
    
    delete ptrBase;
}