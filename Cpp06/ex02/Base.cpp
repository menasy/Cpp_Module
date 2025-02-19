/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:53:08 by menasy            #+#    #+#             */
/*   Updated: 2025/02/19 18:09:42 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base* Base::generate(void)
{
    std::srand(std::time(0));
    int random = std::rand() % 3;
    switch (random)
    {
    	case 0:
			std::cout << "A class is created" << std::endl;
    	    return new A();
    	    break;
		case 1:
			std::cout << "B class is created" << std::endl;
			return new B();
			break;
		case 2:
			std::cout << "C class is created" << std::endl;
			return new C();
			break;
    	default:
    	    break;
    }
	return NULL;
}
void Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Base *ptr: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Base *ptr: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Base *ptr: C" << std::endl;
	else
		std::cout << "Base &ref: Unknown type" << std::endl;
}

void Base::identify(Base& p)
{
    try
	{
		dynamic_cast<A&>(p);
		std::cout << "Base &ref: A" << std::endl;
	}
	catch(const std::exception& e)
	{
		(void)e;
		try
		{
			dynamic_cast<B&>(p);
			std::cout << "Base &ref: B" << std::endl;
		}
		catch(const std::exception& e)
		{
			(void)e;
			try
			{
				dynamic_cast<C&>(p);
				std::cout << "Base &ref: C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "Base &ref: Unkown type: " << e.what() << std::endl;
			}
		}
	}
	
}
