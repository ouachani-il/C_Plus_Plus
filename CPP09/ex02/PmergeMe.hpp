/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:08:39 by ilouacha          #+#    #+#             */
/*   Updated: 2025/03/19 14:55:31 by ilouacha         ###   ########.fr       */
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
#include <utility>
#include <sstream>
#include <cmath>
#include <ctime>
#include <stdexcept>

class DuplicateValueException : public std::exception {
    public:
        const char* what() const throw() {
            return "Error: Duplicate value detected";
        }
    };
    
class BadInputException : public std::exception {
public:
    const char* what() const throw() {
        return "Error: Bad input detected";
    }
};

class InvalidNumberException : public std::exception {
public:
    const char* what() const throw() {
        return "Error: Invalid number detected";
    }
};
    
class PmergeMe {
    public:
    
    // ****************construtor in canonical form
    PmergeMe();
    //PmergeMe(std::vector<unsigned int> Vect);
    PmergeMe(PmergeMe const & src);
    PmergeMe&   operator=(PmergeMe const & rhs);
    ~PmergeMe();
    
    std::vector<unsigned int>    getVector() const;
    std::deque<unsigned int>     getDeque() const;

    void    parsing(int ac, char **av);
    void    print_results(int ac, char **av);
    // Ford-Johnson sort function
    void    fordJohnson(std::vector<unsigned int>& vec);
    void    fordJohnson(std::deque<unsigned int>& deq);
    void    printPairs(std::vector<std::pair<unsigned int, unsigned int> >& pairs);
    void    printPairs(std::deque<std::pair<unsigned int, unsigned int> >& pairs);
    void    print_fjSequence(std::vector<unsigned int>& s, unsigned int b_size);
    void    print_fjSequence(std::deque<unsigned int>& s, unsigned int b_size);
    static double getElapsedTime(const std::clock_t start, const std::clock_t end);
    
        
    private:
        //int err;
        std::vector<unsigned int>    _Vector;
        std::deque<unsigned int>     _Deque;
        
        std::vector<std::pair<unsigned int, unsigned int> > createPairs(std::vector<unsigned int>& elements);
        std::deque<std::pair<unsigned int, unsigned int> > createPairs(std::deque<unsigned int>& elements);

        size_t  count_word_and_check(std::string &str) const;

        void mergeSort(std::vector<std::pair<unsigned int, unsigned int> >& pairs, unsigned int left, unsigned int right);
        void mergeSort(std::deque<std::pair<unsigned int, unsigned int> >& pairs, unsigned int left, unsigned int right);

        void merge(std::vector<std::pair<unsigned int, unsigned int> >& pairs, unsigned int left, unsigned int mid, unsigned int right);
        void merge(std::deque<std::pair<unsigned int, unsigned int> >& pairs, unsigned int left, unsigned int mid, unsigned int right);

        void insertUncools(std::vector<unsigned int>& mainChain, std::vector<unsigned int>& b);
        void insertUncools(std::deque<unsigned int>& mainChain, std::deque<unsigned int>& b);

        void binarySearch(std::vector<unsigned int>& sortedVec, unsigned int value);
        void binarySearch(std::deque<unsigned int>& sortedDeq, unsigned int value);
        //*********************************************** */
    
};

// surcherge d'operateur << pour l'affichage du contenu du container
std::ostream& operator<<(std::ostream &os, std::vector<unsigned int> & obj);
std::ostream& operator<<(std::ostream &os, std::deque<unsigned int> & obj);



#endif