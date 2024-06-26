/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:00:00 by ilouacha          #+#    #+#             */
/*   Updated: 2024/05/17 11:06:31 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void){

	Fixed	a;
	Fixed	b( a );
	Fixed	c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return 0;
}