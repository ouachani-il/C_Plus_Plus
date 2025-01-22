/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:15:13 by ilouacha          #+#    #+#             */
/*   Updated: 2025/01/22 12:30:13 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <cstdlib>

template<typename T>
void    swap(T & a, T & b){
	T	temp;

	temp = b;
	b = a;
	a = temp;
	return ;
}

template<typename T>
T &	max(T & a, T & b){
	return ( a > b ? a : b );
}

template<typename T>
T &	min(T & a, T & b){
	return (  a < b ? a : b );
}
#endif

