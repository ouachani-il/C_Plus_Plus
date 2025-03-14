/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:54:40 by ilouacha          #+#    #+#             */
/*   Updated: 2025/03/14 15:29:19 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cstdlib> 
#include <ctime>

int main(int argc, char **argv){
    try{
        if (argc > 2){
            PmergeMe< std::vector<int> >   vector(argc, argv);
            PmergeMe< std::deque<int> >   deque(argc, argv);
            std::cout << "Before: " << deque << std::endl;
            deque.sorting();
            vector.sorting();
            std::cout << "After: " << deque << std::endl;
            
            deque.sort_time();
            vector.sort_time();
        }
        else{
            throw "Error: bad inputs.";
        }
    }
    catch(...){
        std::cerr << "Error: bad sorting " << std::endl;
    }
    return 0;
}
