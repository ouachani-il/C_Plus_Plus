/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:57:17 by ilouacha          #+#    #+#             */
/*   Updated: 2025/02/12 11:12:34 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Array.hpp"

template<typename T>
Array<T>::Array(){
    
}
template<typename T>
Array<T>::Array(size_t n){
    
}
template<typename T>
Array<T>::Array(Array cont & src){
    
}
template<typename T>
Array & Array<T>::operator=(Array const & rhs){
    
}
template<typename T>
Array<T>::~Array(){
    delete[]    data;
}
size_t    Array::size() const{
    
}
