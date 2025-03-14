/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:54:40 by ilouacha          #+#    #+#             */
/*   Updated: 2025/03/14 15:49:23 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cstdlib> 
#include <ctime>

bool    hasDoubles(std::vector<int>& set){
    std::vector<int>    vect; // the vector where to put the unique elements
    std::vector<int>::iterator  it;
    
    for (it = set.begin(); it != set.end(); it++){
        if (std::find(vect.begin(), vect.end(), *it) != vect.end()){
            std::cerr << "Error : Duplicated integer found." << *it << std::endl;
            return true;
        }
        vect.push_back(*it);
        
    }
    return false;
}
int main(int argc, char **argv){
    try{
        if (argc < 2)
            throw std::runtime_error("Error: Please provide a set of positive integers");
        // testing if there is negative integers
        std::vector<int> input_integers;
        for (int i = 1; i < argc; i++){
            int element = std::atoi(argv[i]);
            if ( element <= 0){
                throw std::runtime_error("Error: negativ input detected. Please provide only positive integers.");
            }
            input_integers.push_back(element);
        }
        if (hasDoubles(input_integers))
            throw std::runtime_error("Error: doubles are detected.");        
    }
}
