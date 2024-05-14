/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:13:27 by ilouacha          #+#    #+#             */
/*   Updated: 2024/05/14 14:20:54 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "sed.hpp"


int	main(int ac, const char *av[]){
	
	/*std::cout << "Please enter the filename \t:" << std::flush;
	std::cin >> filename ;
	std::cout << std::endl;
	std::cout << "Please enter the string to search and replace\t:" << std::flush;
	std::cin >> s1;
	std::cout << std::endl;
	std::cout << "Please enter the string to replace with \t:" << std::flush;
	std::cin >> s1;
	std::cout << std::endl;*/

	if (ac != 4){
		std::cout << "Not enough arguments or much arguments !\n" << std::endl;
		return 1;
	}

	std::ifstream	fin;
	fin.open(av[1]);

	if (!fin.is_open())
	{
		std::cout << "can not open file \n" << std::endl;
		return 1;
	}
	std::string	s1 = av[2];
	std::string	s2;
	s2 = av[3];
	if ( s1.empty() || s2.empty())
	{
		std::cout << "error : empty chain !" << std::endl;
		return 1;
	}
		
	std::string	output_file = "";
	output_file += av[1];
	output_file += ".replace";
	
	std::ofstream	fout;
	fout.open(output_file.c_str());
	if (!fout.is_open())
	{
		std::cout << "cannot open file " << output_file << " for writing !\n" << std::endl;
	}
	ft_replace(fin, fout, s1, s2);

}