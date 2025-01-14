#include "Converter.hpp"

Converter::Converter() : _type(UNDETERMINED) {}

Converter::Converter(const Converter &src) {
	this->_arg = src.get_arg();
	this->_type = src.get_type();
}

Converter &Converter::operator=(const Converter &rhs) {
	this->_arg = rhs.get_arg();
	this->_type = rhs.get_type();
	return *this;
}

Converter::~Converter() {}

// Getters & Setters
std::string Converter::get_arg(void) const { return this->_arg; }

void Converter::set_arg(const std::string &str) {
	this->_arg = str;
	this->_type = UNDETERMINED;
}

in_type Converter::get_type(void) const { return this->_type; }

// Functions
void Converter::_determine_type(void) {
	_type = INVALID;
	if (this->_arg.length() == 1 && !std::isdigit(this->_arg.at(0))) {
		 _type = CHAR;
		return;
	} else if (this->_arg == "nan" || this->_arg == "nanf") {
		_type = NAN_;
		return;
	} else if (this->_arg == "+inf" || this->_arg == "-inf" ||
						 this->_arg == "+inff" || this->_arg == "-inff") {
		_type = INF;
		return;
	} else {
		this->_determine_int_double_float(this->_arg);
	}
}

void Converter::_determine_int_double_float(std::string str) {
	int i(0);
	int len(str.length());
	bool decimal(false);

	if (str.at(0) == '+' || str.at(0) == '-') i++;
	while (i < len) {
		if (str.at(i) == 'f' && (i + 1 == len) && std::isdigit(_arg.at(i - 1))) {
			this->_type = FLOAT;
			return;
		} else if (str.at(i) == '.') {
			if (decimal == false)
				decimal = true;
			else
				return;
		} else if (!std::isdigit(str.at(i))) {
			return;
		}
		i++;
	}
	if (decimal == true)
		this->_type = DOUBLE;
	else
		this->_type = INT;
}

void Converter::_print_conv_char(void) const {
	char c = this->_arg.at(0);
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void Converter::_print_conv_int(void) const {
	long int check = strtol(this->_arg.c_str(), NULL, 10);
	if (check > INT_MAX || check < INT_MIN) {
		std::cout << "Error: input is an INT, but overflowed." << std::endl;
		return;
	}
	int i = check;
	if (i >= CHAR_MIN && i <= CHAR_MAX) {
		if (std::isprint(i))
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: impossible" << std::endl;
	}
	std::cout << "int: " << i << std::endl;

	// Write float conversion
	std::cout << "float: " << static_cast<float>(i);
	if (i < 1000000)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;

	// Write double conversion
	std::cout << "double: " << static_cast<double>(i);
	if (i < 1000000)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

void Converter::_print_conv_double(void) const {
	double d = strtod(this->_arg.c_str(), NULL);

	// Write char conversion
	if (d >= CHAR_MIN && d < CHAR_MAX + 1) {
		char c = static_cast<char>(d);
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: impossible" << std::endl;
	}

	// Write int conversion
	if (d < INT_MIN || d > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	// Write float conversion
	double tmp;
	std::cout << "float: " << static_cast<float>(d);
	if (modf(d, &tmp) == 0 && d < 999999.5) {
		std::cout << ".0f" << std::endl;
	} else {
		std::cout << "f" << std::endl;
	}

	// Write float conversion
	std::cout << "double: " << d;
	if (modf(d, &tmp) == 0 && d < 999999.5) {
		std::cout << ".0";
	}
	std::cout << std::endl;
}

void Converter::_print_conv_float(void) const {
	float f = strtof(this->_arg.c_str(), NULL);

	// Write char conversion
	if (f >= CHAR_MIN && f < CHAR_MAX + 1) {
		char c = static_cast<char>(f);
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: impossible" << std::endl;
	}

	// Write int conversion
	if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;

	// Write float conversion
	double tmp;
	std::cout << "float: " << f;
	if (modf(f, &tmp) == 0 && f < 999999.5) {
		std::cout << ".0f" << std::endl;
	} else {
		std::cout << "f" << std::endl;
	}

	// Write double
	std::cout << "double: " << static_cast<double>(f);
	if (modf(f, &tmp) == 0 && f < 999999.5) {
		std::cout << ".0";
	}
	std::cout << std::endl;
}

void Converter::_print_conv_nan(void) const {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	// Double nan?
	if (this->_arg == "nan") {
		double d = std::numeric_limits<double>::quiet_NaN();
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	// Float nan?
	else if (this->_arg == "nanf") {
		float f = std::numeric_limits<float>::quiet_NaN();
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
}

void Converter::_print_conv_inf(void) const {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	// Double infinity?
	if (!this->_arg.compare(1, 4, "inf")) {
		double d = std::numeric_limits<double>::infinity();
		if (this->_arg.at(0) == '-') d = -d;
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	// Float infinity?
	else if (!this->_arg.compare(1, 5, "inff")) {
		float f = std::numeric_limits<float>::infinity();
		if (this->_arg.at(0) == '-') f = -f;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
}

// Public function

void Converter::print_conversions(void) {
	if (this->_type == UNDETERMINED) this->_determine_type();
	switch (this->_type) {
		case INVALID:
			std::cout << "This input makes no sense !" << std::endl;
			break;
		case CHAR:
			this->_print_conv_char();
			break;
		case INT:
			this->_print_conv_int();
			break;
		case FLOAT:
			this->_print_conv_float();
			break;
		case DOUBLE:
			this->_print_conv_double();
			break;
		case NAN_:
			this->_print_conv_nan();
			break;
		case INF:
			this->_print_conv_inf();
			break;
		default:
			std::cout << "something went VERY wrong!" << std::endl;
	}
}

