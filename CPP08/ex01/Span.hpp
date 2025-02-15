/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:19:11 by ilouacha          #+#    #+#             */
/*   Updated: 2025/02/15 22:40:59 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_hpp
#include <iostream>
#include <vector>
#include <iterator>
class Span {
  public:
    Span();
    ~Span();
    
    void    addNumber();
    void    shortestSpan();
    void    
  private:
    unsigned int    N;  
};

#endif