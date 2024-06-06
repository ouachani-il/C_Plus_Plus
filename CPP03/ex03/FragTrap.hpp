/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:54:05 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/06 23:07:53 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRAGTRAP_HPP_
# define _FRAGTRAP_HPP_

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {

	
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const & rhs);
	FragTrap 	&operator=(FragTrap const & rhs);
	virtual 	~FragTrap(void);
	
	void 		highFivesGuys(void);

};

#endif