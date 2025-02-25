/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:51:31 by ilouacha          #+#    #+#             */
/*   Updated: 2025/02/25 20:57:41 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <vector>
#include <iterator>


Span::Span(unsigned int N) : _N(N){
    if (N != 0)
        _tab.reserve(N);
}   
Span::Span(Span const & src){
    *this = src;
    
}
Span& Span::operator=(Span const & rhs){
    _N = rhs._N;
    _tab = rhs._tab;
    return (*this);
}
Span::~Span(){
}

void    Span::addNumber(int x){
    if (_tab.size() < _N){
        _tab.push_back(x);
    }
    else {
        throw over_size();
    }
    
} //shortest distance between the numbers stacked
int     Span::shortestSpan(){
    if (_tab.size() <= 1){
        throw numbers_not_enough();
    }
    else {
        std::sort(_tab.begin(), _tab.end());
        int min_dist = std::numeric_limits<int>::max();
        std::vector<int>::iterator it;
        for (it = _tab.begin(); it < _tab.end(); ++it ){
            min_dist = std::min(min_dist, *it - *(it-1));
        }
        return (min_dist);
    }
    
}
// longest distance between the numbers stacked
int     Span::longestSpan(){
    if (_tab.size() <= 1){
        throw numbers_not_enough();
    }
    else {
        std::vector<int>::iterator it_min = std::min_element(_tab.begin(), _tab.end());
        std::vector<int>::iterator it_max = std::max_element(_tab.begin(), _tab.end());
        return (*it_max - *it_min);
    }
   
}

void    Span::addNumbers(std::vector<int>::const_iterator begin, 
    std::vector<int>::const_iterator end){
        if (_tab.size() + std::distance(begin, end) > _N){
            throw over_size();
        }
        _tab.insert(_tab.end(), begin, end);
    }
  
