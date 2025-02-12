/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:16:05 by ilouacha          #+#    #+#             */
/*   Updated: 2025/02/12 11:53:07 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
# include <cstdlib>

template <typename T, typename Func>
void    iter(T* array, size_t len, Func f){
    for (size_t i = 0; i < len; i++){
        f(array[i]);
    }
}

template <typename T>
void printElement(T& x) {
    std::cout << x << std::endl;
}

#endif