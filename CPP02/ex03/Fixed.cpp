/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:03:53 by ilouacha          #+#    #+#             */
/*   Updated: 2024/05/17 15:57:00 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _value(0){
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n): _value( n << _fractBits ){
	//std::cout << "int constructor called" << std::endl;
	
}

Fixed::Fixed( float const n): _value( roundf( n * ( 1 << _fractBits ) ) ){
	//std::cout << "float constructor called" << std::endl;
	
}

Fixed::Fixed(Fixed const & fixed){
	//std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed(void){
	//std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const & rhs){
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const{
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits( int const raw ){
	this->_value = raw;
}
float	Fixed::toFloat( void ) const{
	return static_cast<float>( this->getRawBits() ) / ( 1 << _fractBits );
}

int	Fixed::toInt( void ) const{
	return this->_value >> _fractBits;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & i){
	o << i.toFloat();

	return o;
}

// -----------------------Comparison operators---------------------------

bool	Fixed::operator<(Fixed const & rhs ) const{
	return this->_value < rhs.getRawBits();
}
bool	Fixed::operator>(Fixed const & rhs ) const{
	return this->_value > rhs.getRawBits();
}
bool	Fixed::operator<=(Fixed const & rhs ) const{
	return this->_value <= rhs.getRawBits();
}
bool	Fixed::operator>=(Fixed const & rhs ) const{
	return this->_value >= rhs.getRawBits();
}

bool	Fixed::operator==(Fixed const & rhs ) const{
	return this->_value == rhs.getRawBits();
}

bool	Fixed::operator!=(Fixed const & rhs ) const{
	return this->_value != rhs.getRawBits();
}

// -----------------------Arithmetic operators----------------------------

Fixed	Fixed::operator+(Fixed const & rhs) const{
	return ( Fixed(this->toFloat() + rhs.toFloat()) );
}

Fixed	Fixed::operator-(Fixed const & rhs) const{
	return ( Fixed(this->toFloat() - rhs.toFloat()) );
}

Fixed	Fixed::operator*(Fixed const & rhs) const{
	return ( Fixed((this->toFloat() * rhs.toFloat()) ));//* (1 << _fractBits)) );
}

Fixed	Fixed::operator/(Fixed const & rhs) const{
	//if ( rhs.toFloat() != 0 )
	return ( Fixed((this->toFloat() / rhs.toFloat()) ));// (1 << _fractBits) ) );
}

// -----------------------Incremental decremental operators----------------------------

Fixed &	Fixed::operator++(void){
	++this->_value;
	return ( *this );
}

Fixed &	Fixed::operator--(void){
	--this->_value;
	return ( *this );
}

Fixed	Fixed::operator++( int ){
	Fixed	tmp( *this );
	tmp._value = this->_value++;
	return ( tmp );
}

Fixed	Fixed::operator--( int ){
	Fixed	tmp( *this );
	tmp._value = this->_value--;
	return ( tmp );
}

// -----------------------Min and Max---------------------------------------

Fixed &	Fixed::min(Fixed & lhs, Fixed & rhs ){
if ( lhs.getRawBits() < rhs.getRawBits())
	return lhs;
return rhs;
}
	
const Fixed &	Fixed::min(Fixed const & lhs, Fixed const & rhs ){
if ( lhs.getRawBits() < rhs.getRawBits())
	return lhs;
return rhs;
}

Fixed &	Fixed::max(Fixed & lhs, Fixed & rhs ){
if ( lhs.getRawBits() > rhs.getRawBits())
	return lhs;
return rhs;
}
	
const Fixed &	Fixed::max(Fixed const & lhs, Fixed const & rhs ){
if ( lhs.getRawBits() > rhs.getRawBits())
	return lhs;
return rhs;
}
