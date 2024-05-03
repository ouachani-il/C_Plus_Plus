/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 06:47:51 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/05/03 07:13:23 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HARL_HPP_
# define _HARL_HPP_

# include <string>
# include <iostream>

class Harl{
    
public:
    Harl();
    ~Harl();
    void	Harl::complain(std::string level);

private:
void	debug();
void	info();
void	warning();
void	error();

};

typedef void (Harl::*t_func)(void);
#endif 