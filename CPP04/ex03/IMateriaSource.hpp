/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 04:36:19 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/13 04:40:19 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _IMATERIASOURCE_HPP_
# define _IMATERIASOURCE_HPP_

# include "AMateria.hpp"

class IMateriaSource
{
public:
virtual ~IMateriaSource() {}
virtual void learnMateria(AMateria*) = 0;
virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif