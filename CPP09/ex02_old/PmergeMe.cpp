/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:40:36 by ilouacha          #+#    #+#             */
/*   Updated: 2025/03/11 11:31:45 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// construtor in canonical form
PmergeMe::PmergeMe(std::vector<unsigned int> const & input_integers) : _vector(input_integers){
    _deque.assign(input_integers.begin(), input_integers.end());
}
PmergeMe::PmergeMe(PmergeMe const & src){
    *this = src;
}
PmergeMe&   PmergeMe::operator=(PmergeMe const & rhs){
    _vector = rhs._vector;
    _deque = rhs._deque;
    return (*this);
}
PmergeMe::~PmergeMe(){
    
}

// Setters and getters
void    PmergeMe::setVect(std::vector<unsigned int> const &newVect){
    _vector = newVect;
}
void    PmergeMe::setDeq(std::deque<unsigned int> const &newDeq){
    _deque = newDeq;
}
std::vector<unsigned int>    PmergeMe::getVect(){
    return (_vector);
}
std::deque<unsigned int>    PmergeMe::getDeq(){
    return (_deque);
}

//  Ford & Jonhson sorting algorithm
void    sortingAlgVec(std::vector<unsigned int>& vect){
    
}
void    sortingAlgDeq(std::vector<unsigned int>& deq){
    
}

    // Making pairs for each of the vector and the deque containers

void    PmergeMe::makePairsVec(){
    size_t len = _vector.size();
    if (len % 2 == 0)
        _last = -1;
    else{
        len--;
        _last = _vector[len];
    }
    for (size_t it = 0; it < len; it += 2){
        std::pair<unsigned int, unsigned int> p;
        if (_vector[it] > _vector[it+1]){
            p.first = _vector[it + 1];
            p.second = _vector[it];            
        }
        else{            
            p.first = _vector[it];
            p.second = _vector[it + 1];            
        }
        _vecPairs.push_back(p);
    }
}
void    PmergeMe::makePairsDeq(){
    
    size_t len = _deque.size();
    if (len % 2 == 0)
        _last = -1;
    else{
        len--;
        _last = _deque[len];
    }
    for (size_t it = 0; it < len; it += 2){
        std::pair<unsigned int, unsigned int> p;
        if (_deque[it] > _deque[it+1]){
            p.first = _deque[it + 1];
            p.second = _deque[it];            
        }
        else{            
            p.first = _deque[it];
            p.second = _deque[it + 1];            
        }
        _deqPairs.push_back(p);
    }}

template <typename T>    
void    PmergeMe::sortDisplay(const T& containers) const
{
    typename T::const_iterator it;
    for (it = containers.begin(); it != containers.end(); ++it)
        std::cout << *it << " ";
    std::cout<<std::endl;
}

