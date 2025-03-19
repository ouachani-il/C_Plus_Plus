/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:54:40 by ilouacha          #+#    #+#             */
/*   Updated: 2025/03/18 13:43:43 by ilouacha         ###   ########.fr       */
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
            PmergeMe object;

            object.print_results(argc , argv);
                }
        else{
            throw "Error: bad inputs.";
        }
    }
    catch(...){
        std::cerr << "Error: bad trip " << std::endl;
    }
    return 0;
}
