/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:31:57 by ilouacha          #+#    #+#             */
/*   Updated: 2025/02/12 19:45:15 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <new>
#include <exception>

template <typename T>
class Array {
    public: 
        Array();
        Array(unsigned int n);
        Array(Array const & src);
        Array & operator=(Array const & rhs);
        T&  operator[](unsigned int index);
        ~Array();
        unsigned int    size() const;
        class OutOfRangeException : public std::exception
        {
            public :
            const char * what() const throw()
            {
                return ("Element is out of range of array");
            }
        };
        
    private:
        T*   data;
        unsigned int    _n;
    
};

template<typename T>
Array<T>::Array() : data(NULL), _n(0){
    	std::cout << "Default Constructor called" << std::endl;
}
template<typename T>
Array<T>::Array(unsigned int n) : data(NULL), _n(n) {
    std::cout << "param Constructor called" << std::endl;
    if (n > 0){
        data = new T[n];
        if (data == NULL)
            throw std::bad_alloc();
    }
}
template<typename T>
Array<T>::Array(Array const & src) : data(NULL), _n(0) {
    std::cout << " Copy Constructor called" << std::endl;
    *this = src;

}
template<typename T>
Array<T> & Array<T>::operator=(Array const & rhs){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this->_n >= 0 )
        delete [] this->data;
    data = new T[rhs._n];
    _n = rhs._n;
    for (size_t i = 0; i < this->_n; i++){
        data[i] = rhs.data[i];
    }
    return (*this);
}
template<typename T>
Array<T>::~Array(){
    delete[]    data;
}
template<typename T>
unsigned int    Array<T>::size() const{
    
}


template<typename T>
T& Array<T>::operator[](unsigned int index){
        if ((unsigned int)index >= this->_n) 
            throw OutOfRangeException();
        if ((int)index < 0) 
            throw OutOfRangeException();
        return this->data[index];
}

#endif