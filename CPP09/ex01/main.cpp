/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:47:41 by ilouacha          #+#    #+#             */
/*   Updated: 2025/03/02 14:42:00 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv){
    if (argc == 1){
        throw std::runtime_error("Error : Not enough arguments");
        return 1;
    }
    try{
        RPN rpn(argv[1]);
        std::cout << rpn.compute() << std::endl;
    }
    catch(const std::runtime_error& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
    
}