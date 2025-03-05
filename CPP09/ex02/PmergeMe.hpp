/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:08:39 by ilouacha          #+#    #+#             */
/*   Updated: 2025/03/05 16:52:23 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ctime>
#include <vector>
#include <deque>


class PmergeMe{
    private:
        std::vector<int>    _vector;
        std::deque<int>     _deque;

        
    public:
    // construtor in canonical form
        PmergeMe(std::vector<int> const & input_integers);
        PmergeMe(PmergeMe const & src);
        PmergeMe&   operator=(PmergeMe const & rhs);
        ~PmergeMe();
    
    // Setters and getters
        void    setVect(std::vector<int> const &newVect);
        void    setDeq(std::deque<int> const &newDeq);
        std::vector<int>    getVect();
        std::deque<int>    getDeq();

    //  Ford & Jonhson sorting algorithm
        void    FordJonhsonAlg(std::vector<int>& vect);
        void    fordJonhsonAlg(std::vector<int>& deq);
        
};
#endif