/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:45:06 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/17 16:14:15 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CURE_HPP_
# define _CURE_HPP_

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"


class Cure : public AMateria
{
private:
	std::string	_type;
	
public:
Cure(void);
Cure(std::string const &type);
Cure(Cure const &src);
virtual	~Cure(void);
Cure	&operator=(Cure const &rhs);


//virtual std::string const & getType() const;
virtual Cure* clone() const;
virtual void use(ICharacter& target);
};

std::ostream	&operator<<(std::ostream &o, Cure const &i);
#endif