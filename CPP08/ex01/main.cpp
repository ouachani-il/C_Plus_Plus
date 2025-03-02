/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:18:38 by ilouacha          #+#    #+#             */
/*   Updated: 2025/02/28 21:08:51 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ostream>
#include <vector>
#include <list>
#include <ctime>

int main()
{
Span sp = Span(20);
try 
{
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
} 
catch (const std::exception& e) 
{
    std::cerr << "Exception caught: " << e.what() << std::endl;
}

int arr[] = {1, 2, 3, 4, 5};
std::vector<int> test(arr, arr + 5);
try
{
    sp.addNumbers(test.begin(), test.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl; 
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}

std::cout << "---- Test with 10 000 values ----" << std::endl;

Span sp_verybig(10000);
std::vector<int> numbers;
int size = 10000;
int min = 0, max = 10000;
std::srand(std::time(0));
for (int i = 0; i < size; ++i) 
{
    numbers.push_back(min + (std::rand() % (max - min + 1)));
}
/* for (size_t i = 0; i < numbers.size(); ++i) 
{
    std::cout << numbers[i] << " ";
} */
try 
{
    sp_verybig.addNumbers(numbers.begin(), numbers.end());
} 
catch (const Span::over_size& e) 
{
    std::cerr << "Exception caught: " << e.what() << std::endl;
}
std::cout << std::endl;
try 
{
    std::cout << sp_verybig.shortestSpan() << std::endl;
} 
catch (const std::exception& e) 
{
    std::cerr << "Exception caught: " << e.what() << std::endl;
}
try 
{
    std::cout << sp_verybig.longestSpan() << std::endl;
} 
catch (const std::exception& e) 
{
    std::cerr << "Exception caught: " << e.what() << std::endl;
}
return 0;
}