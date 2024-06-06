/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:37:53 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/06 17:24:11 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DIAMONDTRAP_HPP_
# define _DIAMONDTRAP_HPP_

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"


class DiamondTrap : public ScavTrap , public FragTrap {
	
private:
	std::string	_name;

public:
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap & const rhs);
	DiamondTrap	&operator=(DiamondTrap const &rhs);
	virtual	~DiamondTrap(void);

	void		whoAmI();
void attack(const std::string &target) ;

};

#endif