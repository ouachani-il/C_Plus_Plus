/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:08:10 by ilouacha          #+#    #+#             */
/*   Updated: 2024/05/17 18:33:06 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"


Fixed	crossProduct( const Point& a, const Point& b )
{
	return (a.getX() * b.getY() - a.getY() * b.getX());
}

/**
 * @brief This function computes wheather th point is in the triangle formed 
 * by the three points a, b and c. And this is possible by computing three 
 * cross products which should have the same sign. Namely aPxab, bcxbP and
 * cPxca. Hence all of those vectors should be computed.
 * 
 * @param a 
 * @param b 
 * @param c 
 * @param point 
 * @return true 
 * @return false 
 */
bool bsp( Point const a, Point const b, Point const c, Point const point){
	Point ab = Point::ftVector(a, b);
	Point ap = Point::ftVector(a, point);
	std::cout << "ab x = " << ab.getX() << "ab y = " << ab.getY() << std::endl;

	Point bc = Point::ftVector(b, c);
	Point bp = Point::ftVector(b, point);

	Point ca = Point::ftVector(c, a);
	Point cp = Point::ftVector(c, point);

	// Now we should compute the cross products

	Fixed	abp = crossProduct(ab, ap);
	Fixed	bcp = crossProduct(bc, bp);
	Fixed	cap = crossProduct(ca, cp);
	std::cout << "abp = " << abp.toFloat() << "bcp = " << bcp.toFloat() 
		<< "cap = " << cap.toFloat() << std::endl;

	if (( abp < 0 && bcp < 0 && cap < 0 ) || (abp < 0 && bcp < 0 && cap < 0 ))
		return true;
	return false;
}

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