/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:19:11 by ilouacha          #+#    #+#             */
/*   Updated: 2025/02/25 20:58:52 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <iterator>

class Span {
  public:
    Span(unsigned int N);
    Span(Span const & src);
    Span& operator=(Span const & rhs);
    ~Span();
    
    void    addNumber(int x);
    void    addNumbers(std::vector<int>::const_iterator begin, 
      std::vector<int>::const_iterator end);
    int     shortestSpan(); //shortest distance between the numbers stacked
    int     longestSpan(); // longest distance between the numbers stacked

    class over_size : public std::exception{
      public:
        virtual const char* what() const throw(){
          return ("Max size reached ! Cannot add !");
        }
    };
    class numbers_not_enough: public std::exception{
      public:
        virtual const char* what() const throw(){
          return ("Numbers are not enough !");
        }
    };
  private:
    unsigned int    _N;
    std::vector<int> _tab;  
};

#endif