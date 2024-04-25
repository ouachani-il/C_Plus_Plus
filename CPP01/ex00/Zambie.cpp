/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zambie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:38:21 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/25 10:08:27 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iomanip>
#include <iostream>
#include "Zambie.hpp"

Zambie::Zambie(void){	
}
Zambie::~Zambie(void){	
}
void    Zambie::annonce(void) const{
	std::cout << this->_name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}
Zambie*	Zambie::newZambie(std::string nom){
	Zambie*	z = new Zambie("")
}
