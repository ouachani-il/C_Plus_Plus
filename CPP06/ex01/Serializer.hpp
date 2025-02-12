/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:16:19 by ilouacha          #+#    #+#             */
/*   Updated: 2025/01/24 17:29:34 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER__HPP
#define SERIALIZER__HPP

#include <stdint.h>
#include <iostream>

struct Data
{
	int i, j;
};


class Serializer 
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer &src);
		Serializer &operator= (const Serializer &rhs);
		~Serializer();

};


#endif