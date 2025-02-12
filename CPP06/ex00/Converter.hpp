#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ios>
#include <climits>
#include <limits>

class Converter
{
    private:

    Converter();
    Converter (Converter const &src);
    Converter &operator=(Converter const &rhs);
    ~Converter();
    
    
    public:

    static void convert(std::string const &str); 

    static void write_char(char c);
    static void write_float(double f , std::string str);
    static void write_double(double d , std:: string str);



    

};

#endif
