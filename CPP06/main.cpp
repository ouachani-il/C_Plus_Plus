/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:18:50 by ilouacha          #+#    #+#             */
/*   Updated: 2024/09/13 16:21:38 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"
#include <ios>
#include <iomanip>

int	main(int ac, char **av){
	if (ac == 2)
		ScalarConvert::convert(av[1]);
	else
		std::cout << "Undefined behaviorr" << std::endl;
	return 0;
}