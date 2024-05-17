/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:01:23 by ilouacha          #+#    #+#             */
/*   Updated: 2024/05/17 15:17:10 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
# define _FIXED_HPP_

# include <iostream>
# include <string>
#include <cmath>

class Fixed{
	
private:
	
	int	_value;
	static const int	_fractBits = 8;

	
public:
	Fixed(void);
	Fixed(int const n);
	Fixed(float const n);
	Fixed(Fixed const & fixed);
	~Fixed();

	Fixed&	operator=(Fixed const & rhs);

	int getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int	toInt( void ) const;
// -----------------------Comparison operators---------------------------
	bool	operator<(Fixed const & rhs ) const;
	bool	operator>(Fixed const & rhs ) const;
	bool	operator<=(Fixed const & rhs ) const;
	bool	operator>=(Fixed const & rhs ) const;

	bool	operator==(Fixed const & rhs ) const;
	bool	operator!=(Fixed const & rhs ) const;

	

	
// -----------------------Arithmetic operators----------------------------
	
	Fixed	operator+(Fixed const & rhs) const;
	Fixed	operator-(Fixed const & rhs) const;
	Fixed	operator*(Fixed const & rhs) const;
	Fixed	operator/(Fixed const & rhs) const;

// -----------------------Incremental decremental operators----------------------------
	Fixed &	operator++(void);
	Fixed &	operator--(void);
	Fixed	operator++( int );
	Fixed	operator--( int);

// -----------------------Min and Max---------------------------------------
	
	static Fixed &	min(Fixed & lhs, Fixed & rhs );
	static const Fixed &	min(Fixed const & lhs, Fixed const & rhs );
	static Fixed &	max(Fixed & lhs, Fixed & rhs );
	static const Fixed &	max(Fixed const & lhs, Fixed const & rhs );
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

#endif