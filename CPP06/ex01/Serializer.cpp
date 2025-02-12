/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:15:41 by ilouacha          #+#    #+#             */
/*   Updated: 2025/01/24 17:29:47 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
//#include <cstdint>


Serializer::Serializer()
{
	std::cout << "Default Serializer Constructor" << std::endl;
}
Serializer::Serializer(const Serializer &src)
{
	*this = src;
	std::cout << "Copy Serializer Constructor" << std::endl;
}
Serializer &Serializer::operator= (const Serializer &rhs)
{
	(void) rhs;
	std::cout << "Copy Serializer Assignement" << std::endl;
	return *this;
}
Serializer::~Serializer()
{
	std::cout << "Default Serializer Destructor" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}