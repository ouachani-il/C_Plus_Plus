/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:54:40 by ilouacha          #+#    #+#             */
/*   Updated: 2025/03/19 14:52:34 by ilouacha         ###   ########.fr       */
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
        if (argc >= 2){
            PmergeMe object;
            object.print_results(argc , argv);
        }else{
            throw BadInputException();
            //std::cerr <<"Error : wrong number of arguments"<<std::endl;
            //return 1;
        }
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
        //return 1;
    }
    catch (...) {  
        std::cerr << "Bad trip !" << std::endl;
    }
    return 0;
}
