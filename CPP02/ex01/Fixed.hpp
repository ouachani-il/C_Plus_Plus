/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:01:23 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/07 16:13:23 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
# define _FIXED_HPP_

# include <iostream>
# include <string>
class Fixed{
	public:
	Fixed(void);
	Fixed(int const n);
	Fixed(float const n);
	Fixed(Fixed const & fixed);
	~Fixed();

	Fixed&	operator=(Fixed const & rhs);
	int 	getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	
	private:
	int	_value;

	static const int	_fractBits = 8;
	
	
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

#endif