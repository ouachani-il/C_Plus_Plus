/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:08:39 by ilouacha          #+#    #+#             */
/*   Updated: 2025/03/18 15:12:54 by ilouacha         ###   ########.fr       */
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
class PmergeMe {
    public:
    
    // ****************construtor in canonical form
    PmergeMe();
    //PmergeMe(std::vector<unsigned int> Vect);
    PmergeMe(PmergeMe const & src);
    PmergeMe&   operator=(PmergeMe const & rhs);
    ~PmergeMe();
    
    std::vector<unsigned int>   getVector() const;
    std::deque<unsigned int>    getDeque() const;
        
    void    parsing(int ac, char **av);
    void    sorting();
    void    sort_timeV();
    void    sort_timeD();
    void    print_results(int ac, char **av);
    int     binary_search(std::vector<unsigned int > &vecteur, unsigned int b);
        
    private:
        std::vector<unsigned int>    _Vector;
        std::deque<unsigned int>     _Deque;
        time_t  _startV;
        time_t  _endV;
        time_t  _startD;
        time_t  _endD;
        
        float   timeV();
        float   timeD();
        int     Jacobsthal(int i);
        // vector sorting
        void    insert(std::vector<unsigned int> &main, std::vector<unsigned int> &pend, unsigned int odd, std::vector<unsigned int> &left, 
                    std::vector<unsigned int> &vec, bool is_odd, unsigned int order);
        void    sorting(std::vector<unsigned int> & vec);
        // Deque sorting
        void    insert(std::deque<unsigned int> &main, std::deque<unsigned int> &pend, unsigned int odd, std::deque<unsigned int> &left, 
                    std::deque<unsigned int> &vec, bool is_odd, unsigned int order);
        void    sorting(std::deque<unsigned int> & vec);
        size_t  count_word_and_check(std::string &str) const;
    
};

// surcherge d'operateur << pour l'affichage du contenu du container
std::ostream& operator<<(std::ostream &os, std::vector<unsigned int> & obj);
std::ostream& operator<<(std::ostream &os, std::deque<unsigned int> & obj);


//A la palce d'upper_bound, il faudrait utiliser binary search !

#endif