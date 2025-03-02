/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:26:35 by ilouacha          #+#    #+#             */
/*   Updated: 2025/02/28 21:59:43 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <vector>
#include <iterator>
#include <iostream>
#include <stack>
#include <cstdlib>

template <typename T>
class MutantStack : public std::stack<T>{
    public:
        MutantStack();
        MutantStack(MutantStack<T> const & src);
        MutantStack &    operator=(MutantStack const & rhs);
        virtual ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator    iterator;
        typedef typename std::stack<T>::container_type::const_iterator    const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator    reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator    const_reverse_iterator;
    
        iterator    begin();
        iterator    end();
        const_iterator  cbegin() const;
        const_iterator  cend() const;
        reverse_iterator    rbegin();
        reverse_iterator    rend();
        const_reverse_iterator    crbegin() const;
        const_reverse_iterator    crend() const;
};  

template <typename T>
MutantStack<T>::MutantStack(){
    std::cout << "MutantStack constructor" << std::endl;
}
template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const & src){
    *this = src;
}
template <typename T>
MutantStack<T> &    MutantStack<T>::operator=(MutantStack const & rhs){
    return std::stack<T>::operator=(rhs);
}
template <typename T>
MutantStack<T>::~MutantStack(){
    std::cout << "MutantStack destructor" << std::endl;   
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}
template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const
{
    return this->c.begin();
}
template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() const
{
    return this->c.end();
}
template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return this->c.rbegin();
}
template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return this->c.rend();
}
template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const
{
    return this->c.rbegin();
}
template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const
{
    return this->c.rend();
}


#endif