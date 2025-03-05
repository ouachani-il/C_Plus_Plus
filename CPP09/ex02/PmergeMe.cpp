/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:40:36 by ilouacha          #+#    #+#             */
/*   Updated: 2025/03/05 16:52:47 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// construtor in canonical form
PmergeMe::PmergeMe(std::vector<int> const & input_integers) : _vector(input_integers){
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
void    PmergeMe::setVect(std::vector<int> const &newVect){
    _vector = newVect;
}
void    PmergeMe::setDeq(std::deque<int> const &newDeq){
    _deque = newDeq;
}
std::vector<int>    PmergeMe::getVect(){
    return (_vector);
}
std::deque<int>    PmergeMe::getDeq(){
    return (_deque);
}

//  Ford & Jonhson sorting algorithm
void    FordJonhsonAlg(std::vector<int>& vect){
    
}
void    fordJonhsonAlg(std::vector<int>& deq){
    
}
