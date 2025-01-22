/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:15:13 by ilouacha          #+#    #+#             */
/*   Updated: 2025/01/22 12:17:50 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
void    swap(T const & a, T const & b){
	T	temp;

	temp = b
	b = a;
	a = temp;
	return ;
}

template<typename T>
T const &	max(T const & a, T const & b){
	return ( a > b ? a : b );
}

template<typename T>
T const &	min(T const & a, T const & b){
	return (  a < b ? a : b );
}

