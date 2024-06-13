/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:29:34 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/13 02:13:47 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BRAIN_HPP_
# define _BRAIN_HPP_

# include <iostream>
# include <string>

class Brain {
	
public:
	Brain(void);
	Brain(Brain const &src);
	Brain			&operator=(Brain const &rhs);
	virtual			~Brain(void);
	
	//std::string		getIdeas(unsigned int i) const;
	//void			setIdeas(std::string str, unsigned int i);
	
	std::string*	ideas[100];
};
	//Brain(std::string str);
#endif
