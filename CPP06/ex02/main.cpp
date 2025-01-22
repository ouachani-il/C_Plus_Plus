/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:33:58 by ilouacha          #+#    #+#             */
/*   Updated: 2024/12/17 14:34:23 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	srand (time(NULL));
	int j = rand() %3;
	if (j == 0) 
		return new A();
	if (j == 1)
		return new B();
	return new C();

}

void identify(Base* p)
{
	if(!p)
		std::cout<<"pointer NULL"<< std::endl;
	if(dynamic_cast<A*>(p))
		std::cout<<"type A"<< std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout<<"type B"<< std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "type C"<< std::endl;
}


void identify(Base& p)
{
	try
	{
		A& new_d = dynamic_cast<A&>(p);
		std::cout<<"type A"<< std::endl;
		(void)new_d;
	}
	catch(const std::exception &)
	{
	}
	try
	{
		B& new_d = dynamic_cast<B&>(p);
		std::cout<<"type B"<< std::endl;
		(void)new_d;
	}
	catch(const std::exception &)
	{
	}
	try
	{
		C& new_d = dynamic_cast<C&>(p);
		std::cout<<"type C"<< std::endl;
		(void)new_d;
	}
	catch(const std::exception &)
	{
	}
}


int main()
{
	{
		Base * base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	{
		Base * base2 = generate();
		identify(base2);
		identify(*base2);
		delete base2;
	}

}