/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 04:36:19 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/20 15:29:02 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _IMATERIASOURCE_HPP_
# define _IMATERIASOURCE_HPP_

# include "AMateria.hpp"
# include "ICharacter.hpp"


class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif