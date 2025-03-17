/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:54:40 by ilouacha          #+#    #+#             */
/*   Updated: 2025/03/17 12:24:26 by ilouacha         ###   ########.fr       */
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
            PmergeMe< std::vector<int> >   Vector(argc, argv);
            PmergeMe< std::deque<int> >   Deque(argc, argv);
            std::cout << "Before: " << Deque << std::endl;
            Deque.sorting();
            Vector.sorting();
            std::cout << "After: " << Deque << std::endl;
            
            Deque.sort_time();
            Vector.sort_time();
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
