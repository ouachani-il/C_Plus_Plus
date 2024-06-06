/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:03:57 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/06 12:53:56 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCAVTRAP_HPP_
# define _SCAVTRAP_HPP_

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap{
private:
	bool	_guardMode;
	
public:
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & rhs);
	ScavTrap 	&operator=(ScavTrap const & rhs);
	virtual		~ScavTrap(void);
	
	void 			guardGate(void);
	bool			getGuardMode(void) const;
	void 			attack(const std::string &target);

};

#endif