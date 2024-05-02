/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:55:53 by ilouacha          #+#    #+#             */
/*   Updated: 2024/05/02 17:21:42 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
//# include <

class Harl{
	
public:
	Harl();
	~Harl();

	void	complain(std::string level);

private:
void	debug();
void	info();
void	warning();
void	error();
	
};

typedef void (Harl::*t_func) (void);
#endif // !HARL_HPP
