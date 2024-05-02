/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:55:25 by ilouacha          #+#    #+#             */
/*   Updated: 2024/05/02 17:38:33 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void){

}

Harl::~Harl(){
	
}
void	Harl::complain(std::string level){
	t_func	funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;
	while (i < 4 && levels[i].compare(level))
		i++;
	if (i < 4)
		(this->*funcs[i])();
	else
		std::cout << "It is not a valid level" << std::endl;
}

void	Harl::debug(void){
	std::cout<<"DEBUG: ";
	std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;

}

void	Harl::info(void){
	std::cout<<"INFO: ";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;

}

void	Harl::warning(void){
	
	std::cout<<"WARNING: ";
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming foryears whereas you started working here since last month." << std::endl;
}

void	Harl::error(void){
	std::cout<<"ERROR: ";
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

