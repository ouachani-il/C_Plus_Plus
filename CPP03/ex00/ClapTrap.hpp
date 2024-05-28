/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:36:11 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/05/28 22:58:30 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLAPTRAP_HPP_
# define _CLAPTRAP_HPP_
# include <iostream>
# include <string>

class ClapTrap{

public:
	ClapTrap(std::string name);
    ClapTrap(ClapTrap const & clapTrap);
    ClapTrap&   operator=(ClapTrap const & rhs);
	~ClapTrap(void);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
    
    /*****Getteurs et setteurs****/
    std::string	_getName(void) const;
    int	_getHitPoints(void) const;
    int	_getEnergyPoints(void) const;
    int	_getAttackDamage(void) const;
private:
	std::string	_name;
	int	_hitPoints;
	int	_energyPoints;
	int	_attackDamage;
};

#endif