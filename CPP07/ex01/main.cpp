/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:15:52 by ilouacha          #+#    #+#             */
/*   Updated: 2025/02/12 11:54:04 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "iter.hpp"


int main(){
    
    int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t  len = sizeof(array) / sizeof(array[0]);
    iter(array, len, printElement<int>);

    std::string string_array[4] = {"maman", "papa", "tata", "coucou" };
    iter(string_array, 3, printElement<std::string>);


    double double_array[3]  = { 0.2 , 1.8 , 6.7};
    iter(double_array, 3 , printElement<double>);

    return 0;
}
