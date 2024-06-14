/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:13:08 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/14 18:53:04 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MATERIASOURCE_HPP_
# define _MATERIASOURCE_HPP_

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
private:
	;
	
public:
MateriaSource(void);
MateriaSource(std::string const &type);
MateriaSource(MateriaSource const &src);
virtual	~MateriaSource(void);
MateriaSource	&operator=(MateriaSource const &rhs);


virtual void learnMateria(AMateria*) {
	
}
virtual AMateria* createMateria(std::string const & type) {
	
}
};

#endif