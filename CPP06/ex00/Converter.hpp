#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <cmath>
#include <iomanip>

enum in_type {
	UNDETERMINED,
	INVALID,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NAN_,
	INF
};

class Converter {
	public:
  		Converter();
  		Converter(const Converter &src);

  		Converter &operator=(const Converter &rhs);

  		~Converter();

  		// Getters & Setters
  		std::string get_arg(void) const;
  		void set_arg(const std::string &str);
		in_type get_type(void) const;

  		// Functions
  		void print_conversions(void);

 	private:
  		std::string _arg;
		in_type	_type;

		//functions
		void 	_determine_type(void);
		void 	_determine_int_double_float(std::string str);
		void 	_print_conv_char(void) const;
		void 	_print_conv_int(void) const;
		void 	_print_conv_double(void) const;
		void 	_print_conv_float(void) const;
		void 	_print_conv_nan(void) const;
		void 	_print_conv_inf(void) const;
};

#endif