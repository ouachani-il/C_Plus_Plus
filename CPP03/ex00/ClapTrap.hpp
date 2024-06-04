/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:36:11 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/04 11:40:19 by ilouacha         ###   ########.fr       */
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
	ClapTrap&	operator=(ClapTrap const & rhs);
	~ClapTrap(void);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	
	/*****Getteurs et setteurs****/
	std::string	_getName(void) const;
	unsigned int	&getHitPoints(void);
	unsigned int	&getEnergyPoints(void);
	unsigned int	&getAttackDamage(void);
	
	void	setName(std::string name);
	void	setHitPoints(unsigned int hitPoints);
	void	setEnergyPoints(unsigned int energyPoints);
	void	setAttackDamage(unsigned int attackD);
private:
	std::string	_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
};

#endif