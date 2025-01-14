/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:05:23 by ilouacha          #+#    #+#             */
/*   Updated: 2024/12/17 14:10:07 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int argc, char **argv) {
	if (argc == 2){
		std::string str = argv[1];
	
		Converter converter = Converter();
		converter.set_arg(str);
		converter.print_conversions();
	}
	else{
		std::cout << "Usage: [./converter <char, int, float or double>]" << std::endl;
	}
	return 0;
}
