#include "Converter.hpp"

// Constructors
Converter::Converter() : type_(UNDETERMINED) {}

Converter::Converter(const Converter &copy) {
  this->arg_ = copy.get_arg();
  this->type_ = copy.get_type();
}

// Destructor
Converter::~Converter() {}

// Operators
Converter &Converter::operator=(const Converter &other) {
  this->arg_ = other.get_arg();
  this->type_ = other.get_type();
  return *this;
}

// Getters & Setters
std::string Converter::get_arg(void) const { return this->arg_; }

void Converter::set_arg(const std::string &str) {
  this->arg_ = str;
  this->type_ = UNDETERMINED;
}

in_type Converter::get_type(void) const { return this->type_; }

// Functions
void Converter::determine_type_(void) {
  type_ = INVALID;
  if (this->arg_.length() == 1 && !std::isdigit(this->arg_.at(0))) {
    type_ = CHAR;
    return;
  } else if (this->arg_ == "nan" || this->arg_ == "nanf") {
    type_ = NAN_;
    return;
  } else if (this->arg_ == "+inf" || this->arg_ == "-inf" ||
             this->arg_ == "+inff" || this->arg_ == "-inff") {
    type_ = INF;
    return;
  } else {
    this->determine_int_double_float_(this->arg_);
  }
}

void Converter::determine_int_double_float_(std::string str) {
  int i(0);
  int len(str.length());
  bool decimal(false);

  if (str.at(0) == '+' || str.at(0) == '-') i++;
  while (i < len) {
    if (str.at(i) == 'f' && (i + 1 == len) && std::isdigit(arg_.at(i - 1))) {
      this->type_ = FLOAT;
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
    this->type_ = DOUBLE;
  else
    this->type_ = INT;
}

void Converter::print_conversions(void) {
  if (this->type_ == UNDETERMINED) this->determine_type_();
  switch (this->type_) {
    case INVALID:
      std::cout << "This input makes no sense!" << std::endl;
      break;
    case CHAR:
      this->print_conversions_char_();
      break;
    case INT:
      this->print_conversions_int_();
      break;
    case FLOAT:
      this->print_conversions_float_();
      break;
    case DOUBLE:
      this->print_conversions_double_();
      break;
    case NAN_:
      this->print_conversions_nan_();
      break;
    case INF:
      this->print_conversions_inf_();
      break;
    default:
      std::cout << "something went VERY wrong!" << std::endl;
  }
}

void Converter::print_conversions_char_(void) const {
  char c = this->arg_.at(0);
  if (std::isprint(c))
    std::cout << "char: '" << c << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
  std::cout << "int: " << static_cast<int>(c) << std::endl;
  std::cout << "float: " << static_cast<float>(c) << std::endl;
  std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void Converter::print_conversions_int_(void) const {
  long int check = strtol(this->arg_.c_str(), NULL, 10);
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

void Converter::print_conversions_double_(void) const {
  double d = strtod(this->arg_.c_str(), NULL);

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

void Converter::print_conversions_float_(void) const {
  float f = strtof(this->arg_.c_str(), NULL);

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
  if (f < INT_MIN || f > INT_MAX)
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

void Converter::print_conversions_nan_(void) const {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  // Double nan?
  if (this->arg_ == "nan") {
    double d = std::numeric_limits<double>::quiet_NaN();
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
  }
  // Float nan?
  else if (this->arg_ == "nanf") {
    float f = std::numeric_limits<float>::quiet_NaN();
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
  }
}

void Converter::print_conversions_inf_(void) const {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;

  // Double infinity?
  if (!this->arg_.compare(1, 4, "inf")) {
    double d = std::numeric_limits<double>::infinity();
    if (this->arg_.at(0) == '-') d = -d;
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
  }
  // Float infinity?
  else if (!this->arg_.compare(1, 5, "inff")) {
    float f = std::numeric_limits<float>::infinity();
    if (this->arg_.at(0) == '-') f = -f;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
  }
}