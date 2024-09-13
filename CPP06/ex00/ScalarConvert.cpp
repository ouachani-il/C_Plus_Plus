/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:00:06 by ilouacha          #+#    #+#             */
/*   Updated: 2024/09/13 16:28:31 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert(){
	std::cout << "ScalarConvert default constructor" << std::endl;
}

ScalarConvert::ScalarConvert(ScalarConvert const &src){
	std::cout << "ScalarConvert copy constructor" << std::endl;
	*this = src;
}

ScalarConvert::~ScalarConvert(){
	std::cout << "ScalarConvert destructor" << std::endl;
}

ScalarConvert	&ScalarConvert::operator=(ScalarConvert const &rhs){
	std::cout << "ScalarConvert copy assignement" << std::endl;
	(void)rhs;
	return *this;
}

