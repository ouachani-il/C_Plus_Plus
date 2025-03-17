/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:08:39 by ilouacha          #+#    #+#             */
/*   Updated: 2025/03/17 16:27:43 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <vector>
#include <iterator>
#include <list>
#include <sstream>
#include <cmath>
#include <ctime>

// a template for the container, to adapt the sorting algorithm for both of the containers chosen to do it.
template <typename Container>
class PmergeMe {
    public:
    
    // construtor in canonical form
    PmergeMe();
    PmergeMe(int argc, char **argv);
    PmergeMe(PmergeMe const & src);
    PmergeMe&   operator=(PmergeMe const & rhs);
    ~PmergeMe();
    
    
    void    sorting();
    void    sort_time();
    
    typename Container::iterator begin();
    typename Container::iterator end();
    
    private:
        std::vector<int>    _Vector;
        std::deque<int>     _Deque;
        time_t  _start;
        time_t  _end;
        
        float   time();
        int     Jacobsthal(int i);
        void    insert(Container &main, Container &pend, ValueType odd, Container &left, Container &vec, bool is_odd, int order);
        void    sorting(Container & vec);
        size_t  count_word_and_check(std::string &str) const;
        std::string container_type();
    
};

// surcherge d'operateur << pour l'affichage du contenu du container
template <typename Container>
std::ostream& operator<<(std::ostream &os, const PmergeMe<Container> &obj);

#include "PmergeMe.tpp"

//A la palce d'upper_bound, il faudrait utiliser binary search !

#endif