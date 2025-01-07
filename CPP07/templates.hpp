/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:48:20 by ilham_oua         #+#    #+#             */
/*   Updated: 2025/01/04 23:42:06 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TEMPLATES_HPP
 #define TEMPLATES_HPP

#include <iostream>

template< typename T >
T const & max(T const & a, T const & b){
    return ( ( a >= b ) ? a : b );
}

template< typename T >
T const & min(T const & a, T const & b){
    return ( ( a < b ) ? a : b );
}

template< typename T >
void swap(T const & a, T const & b){
    T const temp;
    T = a ;
    a = b ;
    b = temp;
}

#endif
