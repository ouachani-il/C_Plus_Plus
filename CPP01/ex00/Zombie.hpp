/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:13:00 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/25 16:04:22 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _Zombie_HPP_
# define _Zombie_HPP_

# include <string>

class Zombie{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	annonce(void) const;
		std::string	_getName(void) const;
		
	private:
		std::string	_name;
};

Zombie*	newZombie(std::string name);
void	randomChump( std::string name );

#endif