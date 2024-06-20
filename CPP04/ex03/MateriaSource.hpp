/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:13:08 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/20 15:30:01 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MATERIASOURCE_HPP_
# define _MATERIASOURCE_HPP_

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
private:
	AMateria*	_materia[4];
	int			_iLearn;
	
public:
	MateriaSource(void);
	MateriaSource(MateriaSource const &src);
	virtual	~MateriaSource(void);
	MateriaSource	&operator=(MateriaSource const &rhs);
	
	
	virtual void 		learnMateria(AMateria*);
	virtual AMateria* 	createMateria(std::string const & type);
};

#endif