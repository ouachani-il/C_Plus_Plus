/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:15:00 by ilouacha          #+#    #+#             */
/*   Updated: 2024/12/17 14:15:21 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <iterator>


int main()
{
	Data *data = new Data();

	data->i = 42;
	data->j = 24;
	uintptr_t ptr = Serializer::serialize(data);
	Data *check  = Serializer::deserialize(ptr);
	std::cout<< check->i << std::endl<<check->j<<std::endl;
	if (Serializer::deserialize(ptr) == data)
			std::cout <<"same"<<std::endl;
	else
		std::cout<< "not the same"<<std::endl;


	delete data;
}