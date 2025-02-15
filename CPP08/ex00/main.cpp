/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:21:16 by ilouacha          #+#    #+#             */
/*   Updated: 2025/02/15 22:17:35 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <deque>
#include <iterator>
#include <vector>
#include <stack>

int main() {
    {
    std::deque<int> s_int;
    s_int.push_back(1);
    s_int.push_back(2);
    s_int.push_back(3);

    std::deque <int> :: iterator it = easyfind(s_int, 3);
    
    std::cout<<*it<<" in index "<<it - s_int.begin()
        << std::endl << "****************************" << std::endl;
        
    }
    
    {std::vector<int>   int_array(4);
    int_array[0] = 4;
    int_array[1] = 5;
    int_array[2] = 6;
    int_array[3] = 7;
    
    std::vector<int>::iterator it = easyfind(int_array, 4);
    
    std::cout << *it << " in index " << it - int_array.begin() 
        << std::endl << "****************************" << std::endl;
    
    }
    
    {
    std::vector<int> int_array(3);
    int_array.push_back(-1);
    int_array.push_back(2);
    int_array.push_back(30);

   if (easyfind(int_array, 2) == int_array.end())
    std::cout<< "non-existent value"<<std::endl;    
   else
   std::cout<<*easyfind(int_array, 2)<< " is here"<< std::endl;

    if (easyfind(int_array, 30000) == int_array.end())
        std::cout<< "non-existent value"<<std::endl;    
    else
        std::cout<<*easyfind(int_array,3000)<<std::endl;
    }
    
    return 0;
   
}
