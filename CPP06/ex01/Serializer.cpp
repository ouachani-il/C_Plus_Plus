/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:15:41 by ilouacha          #+#    #+#             */
/*   Updated: 2024/12/17 14:16:06 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
//#include <cstdint>


Serializer::Serializer()
{
	std::cout << "Default Constructor" << std::endl;
}
Serializer::Serializer(const Serializer &other)
{
	*this = other;
	std::cout << "Copy Constructor" << std::endl;
}
Serializer &Serializer::operator= (const Serializer &other)
{
	(void) other;
	std::cout << "Copy Assignement" << std::endl;
	return *this;
}
Serializer::~Serializer()
{
	std::cout << "Default Destructor" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}