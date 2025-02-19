/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:19:11 by ilouacha          #+#    #+#             */
/*   Updated: 2025/02/19 15:54:54 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_hpp
#include <iostream>
#include <vector>
#include <iterator>
class Span {
  public:
    Span(unsigned int N);
    Span(Span const & src);
    Span& operator=(Span const & rhs);
    ~Span();
    
    void    addNumber();
    int     shortestSpan(); //shortest distance between the numbers stacked
    int     longestSpan(); // longest distance between the numbers stacked
  private:
    unsigned int    _N;  
};

#endif