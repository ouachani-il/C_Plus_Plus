/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:31:09 by ilouacha          #+#    #+#             */
/*   Updated: 2024/05/30 17:32:09 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

#include "Point.hpp"
#include "Fixed.hpp"

int	main(void){
	Point A = Point(0, 0);
	Point B = Point(5, 0);
	Point C = Point(0, 5);
	Point P = Point(1, 1);  // Point to be checked

	if (bsp( A, B, C, P )) {
		std::cout << "Point P is inside the triangle." << std::endl;
	} else {
		std::cout << "Point P is outside the triangle." << std::endl;
	}

	return 0;
}