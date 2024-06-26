/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:45:06 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/20 15:21:46 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CURE_HPP_
# define _CURE_HPP_

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
private:
	std::string	_type;
	
public:
	Cure(void);
	Cure(Cure const &src);
	virtual	~Cure(void);
	Cure	&operator=(Cure const &rhs);
	
	
	//virtual std::string const & getType() const;
	virtual Cure* clone() const;
	virtual void use(ICharacter& target);
};

#endif