/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:31:57 by ilouacha          #+#    #+#             */
/*   Updated: 2025/02/12 12:03:52 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

template <typename T>
class Array {
    Public : 
        Array();
        Array(size_t n);
        Array(Array const & src);
        Array & operator=(Array const & rhs);
        T&  operator[](size_t index);
        ~Array();
        size_t    size() const;
        
    Private:
        T*   data;
        size_t    _n;
    
};

template<typename T>
Array<T>::Array() : data(NULL), _n(0){
    	std::cout << "Default Constructor called" << std::endl;
}
template<typename T>
Array<T>::Array(size_t n) : data(NULL), _n(n) {
    std::cout << "param Constructor called" << std::endl;
    if (n > 0){
        data = new T[n];
        if (data == NULL)
            throw std::bad_alloc();
    }
}
template<typename T>
Array<T>::Array(Array const & src){
    std::cout << " Copy Constructor called" << std::endl;
    this = new Array<T>(other._n);
    *this = src;

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
