/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:03:48 by ilouacha          #+#    #+#             */
/*   Updated: 2024/05/30 17:33:30 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _POINT_HPP_
# define _POINT_HPP_

# include <iostream>
# include "Fixed.hpp"

class Point{
private:
	const Fixed	_x;
	const Fixed	_y;
public:
	Point(void);
	Point(const float x, const float y);
	Point(Point const & pt);
	~Point(void);

	Point& operator=(Point const & rhs);

	Fixed	getX(void) const;
	Fixed	getY(void) const;
	static Point	ftVector(Point const & a, Point const &b);
};


#endif