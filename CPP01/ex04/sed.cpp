/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:56:48 by ilouacha          #+#    #+#             */
/*   Updated: 2024/05/02 16:47:03 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

void	ft_replace(std::ifstream &fin, std::ofstream &output_file, std::string const &s1, std::string const &s2){
	std::string	line;
	
	while (getline(fin, line)){
		int	pos = 0;
		int	new_pos = 0;
		while (new_pos != -1 && pos < (int) line.length()){
			new_pos = line.find(s1, pos);
			if (new_pos != -1)
			{
				std::string	str = line.substr(pos, new_pos);
				output_file << str;
				output_file << s2;
				//pos = new_pos + s1.length();
				line = line.substr(new_pos + s1.length(), line.length() - (new_pos + s1.length()));
			}
			else{
				output_file << line;
			}
		}
		output_file << std::endl;
	}
}
