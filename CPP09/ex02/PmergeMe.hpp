/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:08:39 by ilouacha          #+#    #+#             */
/*   Updated: 2025/03/07 12:41:47 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ctime>
#include <vector>
#include <deque>


class PmergeMe{
    private:
        std::vector<unsigned int>    _vector;
        std::deque<unsigned int>     _deque;
        long    _last;
        
        std::vector<std::pair<unsigned int, unsigned int> >  _vecPairs;
        std::vector<std::pair<unsigned int, unsigned int> >   _deqPairs;
        
    public:
    // construtor in canonical form
        PmergeMe(std::vector<unsigned int> const & input_integers);
        PmergeMe(PmergeMe const & src);
        PmergeMe&   operator=(PmergeMe const & rhs);
        ~PmergeMe();
    
    // Setters and getters
        void    setVect(std::vector<unsigned int> const &newVect);
        void    setDeq(std::deque<unsigned int> const &newDeq);
        std::vector<unsigned int>    getVect();
        std::deque<unsigned int>    getDeq();

    //  Ford & Jonhson sorting algorithm
        void    sortingAlgVec();
        void    sortingAlgDeq();
        
    // Making pairs for each of the vector and the deque containers
        void    makePairsVec();
        void    makePairsDeq();
        
};
#endif