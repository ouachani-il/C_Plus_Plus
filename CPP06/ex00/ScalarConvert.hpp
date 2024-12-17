/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:42:23 by ilouacha          #+#    #+#             */
/*   Updated: 2024/12/17 11:10:19 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALERCONVERT_HPP
# define SCALARCONVERT_HPP

# include <iostream>
# include <string>

class ScalarConvert {
	private:
	
	ScalarConvert();
	ScalarConvert(ScalarConvert const &src);
	~ScalarConvert();
	ScalarConvert	&operator=(ScalarConvert const &rhs);
	
	public:

	static void converter(std::string const &str); 
	static void error_cases();


	static void write_char(char c);
	static void write_float(double f , std::string str);
	static void write_double(double d , std:: string str);
	
};

#endif	