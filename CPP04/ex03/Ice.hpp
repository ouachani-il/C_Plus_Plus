/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:40:39 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/13 13:05:47 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ICE_HPP_
# define _ICE_HPP_

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"


class Ice : public AMateria
{
private:
	std::string	_type;
	
public:
Ice(void);
Ice(std::string const &type);
Ice(Ice const &src);
virtual	~Ice(void);
Ice	&operator=(Ice const &rhs);

//virtual std::string const & getType() const;
virtual Ice* clone() const;
virtual void use(ICharacter& target);
};

#endif