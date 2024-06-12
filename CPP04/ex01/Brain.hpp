/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:29:34 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/12 16:08:27 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BRAIN_HPP_
# define _BRAIN_HPP_

# include <iostream>
# include <string>

class Brain {
protected:
	std::string*	ideas[100];
	
public:
	Brain(void);
	Brain(std::string str);
	Brain(Brain const &src);
	Brain	&operator=(Brain const &rhs);
	virtual			~Brain(void);
	
	std::string		getIdeas(unsigned int i) const;
	void			setIdeas(std::string str, unsigned int i);
	
};
#endif
