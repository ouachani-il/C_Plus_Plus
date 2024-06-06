/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:03:57 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/07 00:01:07 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCAVTRAP_HPP_
# define _SCAVTRAP_HPP_

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
private:
	bool	_guardMode;
	
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & rhs);
	ScavTrap 	&operator=(ScavTrap const & rhs);
	virtual		~ScavTrap(void);
	
	void 			guardGate(void);
	bool			getGuardMode(void) const;
	void 			attack(const std::string &target);

};

#endif