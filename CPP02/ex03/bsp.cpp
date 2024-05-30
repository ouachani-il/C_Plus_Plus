/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:04:04 by ilouacha          #+#    #+#             */
/*   Updated: 2024/05/30 17:34:18 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

/**
 * @brief We should compute the determinent of the following matrix to know 
 * wheather the point P in inside the ABC triangle or not:
 * 
 *			det | xa    ya    1|
				| xb    yb    1|
				| xc    yc    1|

				= xa |yb     1| + xb |ya    1| + xc |ya    1|
					 |yc     1|      |yc    1|      |yb    1|

				= xa( yb - yc) + xb (ya - yc) + xc(ya - yb) 
			   
		airTriangle = abs(det/2) 
					= (
					  a.getX() * [ b.getY() - c.getY() ] + 
					  b.getX() * [ a.getY() - c.getY() ] +
					  c.getX() * [ a.getY() - b.getY()]) / 2

 * Thus, if the sum of the three trinagles airs : ABP + ACP + BCP = air(ABC) => P is inside ABC
 * @param a 
 * @param b 
 * @param c 
 * @param point 
 * @return true 
 * @return false 
 */

static Fixed triangleAir(Point const a, Point const b, Point const c){
/*     std::cout << (( a.getX() * ( b.getY() - c.getY() ) + 
                b.getX() * ( c.getY() - a.getY() ) +
                c.getX() * ( a.getY() - b.getY()) ) / 2 ) << std::endl;*/

	return (( a.getX() * ( b.getY() - c.getY() ) + 
					  b.getX() * ( c.getY() - a.getY() ) +
					  c.getX() * ( a.getY() - b.getY())) / 2 );
}

static Fixed	abs( Fixed x ){
	if ( x < 0)
		return (Fixed (-1) * x);
	return x ;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point){
	Fixed	triangle1 = abs(triangleAir(point, a, b));
	Fixed	triangle2 = abs(triangleAir(point, b, c));
	Fixed	triangle3 = abs(triangleAir(point, a, c));
	Fixed	triangle0 = abs(triangleAir(a, b, c));

	return (triangle0 == (triangle1 + triangle2 + triangle3));
}
