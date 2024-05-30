/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:06:55 by ilouacha          #+#    #+#             */
/*   Updated: 2024/05/30 16:09:41 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0){
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}


Point::Point(Point const & pt) : _x(pt._x), _y(pt._y) {
}

Point::~Point(void){}

Point&	Point::operator=(Point const & rhs){
	if (this != &rhs){
		(Fixed) this->_x = rhs.getX();
		(Fixed) this->_y = rhs.getY();
	}
	return *this;
}

Fixed	Point::getX(void) const{
	return this->_x;
}
Fixed	Point::getY(void) const{
	return this->_y;
}
	
/*Point	Point::ftVector(Point const & a, Point const &b){
	Point	tmp;
	Fixed	x, y;
	
	x = b.getX() - a.getX();
	y = b.getY() - a.getY();
	tmp = Point(x.toFloat(), y.toFloat());
	return tmp;
}*/
