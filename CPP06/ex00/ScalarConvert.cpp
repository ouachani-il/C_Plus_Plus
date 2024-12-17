/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:00:06 by ilouacha          #+#    #+#             */
/*   Updated: 2024/12/17 12:44:43 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>

ScalarConvert::ScalarConvert(){
	std::cout << "ScalarConvert default constructor" << std::endl;
}

ScalarConvert::ScalarConvert(ScalarConvert const &src){
	std::cout << "ScalarConvert copy constructor" << std::endl;
	*this = src;
}

ScalarConvert::~ScalarConvert(){
	std::cout << "ScalarConvert destructor" << std::endl;
}

ScalarConvert	&ScalarConvert::operator=(ScalarConvert const &rhs){
	std::cout << "ScalarConvert copy assignement" << std::endl;
	(void)rhs;
	return *this;
}

void ScalarConvert::error_cases() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static int getPrecision(const std::string &str, double d, bool is_float) {
	int v_min = static_cast<int>(floor(d));
	int v_max = static_cast<int>(ceil(d));
	int log_10 = static_cast<int>(std::log10(v_max));
	int precision =
		(v_min == v_max) ? (log_10 + 2) : (str.length() - 1 - (is_float ? 1 : 0));

	return precision;
}

void ScalarConvert::converter(std::string const &str) {
	char *end_str = NULL;
	std::string tmp;
	double d = std::strtod(str.c_str(), &end_str); 
	std::string end = end_str;

	
	if (str.size() != 1 && end == "f")
		ScalarConvert::write_float(d, str);
	else if ((str.size() != 1 && *end_str == '\0') ||
			 (str.size() == 1 && std::isdigit(str[0])))
		ScalarConvert::write_double(d, str);
	else if (str.size() != 1 && end != "f")
		ScalarConvert::error_cases();
	else if (str.size() == 1 && !std::isdigit(str[0]))
	write_char(str[0]);
}

void ScalarConvert::write_char(char c) {
	int precision = std::log10(c) + 2;
	double d = static_cast<double>(c);
	if (c == ' ' || std::isgraph(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::setprecision(precision) << std::showpoint << d
			<< "f" << std::endl;
	std::cout << "double: " << std::setprecision(precision) << std::showpoint << d
			<< std::endl;
}

void ScalarConvert::write_float(double f, std::string str) {
	char c = static_cast<char>(f);
	int precision = getPrecision(str, f, true);

	if (c == ' ' || std::isgraph(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else if (str == "-inff" || str == "+inff" || str == "nanf")
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;

	if (str == "-inff" || str == "+inff" || str == "nanf")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;

	std::cout << "float: " << std::setprecision(precision) << std::showpoint << f
			<< "f" << std::endl;
	std::cout << "double: " << std::setprecision(precision) << std::showpoint << f
			<< std::endl;
}

void ScalarConvert::write_double(double d, std::string str) {

	char c = static_cast<char>(d);
	int precision = getPrecision(str, d, false);
	if (c == ' ' || std::isgraph(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else if (str == "-inf" || str == "+inf" || str == "nan")
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;

	if (str == "-inf" || str == "+inf" || str == "nan")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << std::setprecision(precision) << std::showpoint << d
			<< "f" << std::endl;
	// std::cout <<"double: "<< d << std::endl;

	std::cout << "double: " << std::setprecision(precision) << std::showpoint << d
			<< std::endl;
}
