/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:51:18 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/06 23:05:56 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLAPTRAP_HPP_
# define _CLAPTRAP_HPP_
# include <iostream>
# include <string>

class ClapTrap{
	
protected:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & clapTrap);
	ClapTrap&	operator=(ClapTrap const & rhs);
	virtual		~ClapTrap(void);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	
	/*****Getteurs et setteurs****/
	std::string		_getName(void) const;
	unsigned int	_getHitPoints(void) const;
	unsigned int	_getEnergyPoints(void) const;
	unsigned int	_getAttackDamage(void) const;

	void	setName(std::string name);
	void	setHitPoints(unsigned int hitPoints);
	void	setEnergyPoints(unsigned int energyPoints);
	void	setAttackDamage(unsigned int attackD);

};
#endif