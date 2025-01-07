/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:48:03 by ilham_oua         #+#    #+#             */
/*   Updated: 2025/01/04 23:45:44 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "templates.hpp"

void    main(void){
    int a = 14;
    int b = 5;

    std::cout << max<int>(a, b) << std::endl;

    float a = 14.3;
    float b = 5.2;

    std::cout << max<float>(a, b) << std::endl;
    return ;
  
}