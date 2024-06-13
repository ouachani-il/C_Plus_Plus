/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 04:30:01 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/13 04:32:11 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AMATERIA_HPP_
# define _AMATERIA_HPP_

# include <iostream>
# include <string>
# include "ICharacter.hpp"


class AMateria
{
protected:

public:
AMateria(std::string const & type);

std::string const & getType() const; //Returns the materia type
virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);
};

#endif