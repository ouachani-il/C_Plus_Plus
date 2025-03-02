/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:47:20 by ilouacha          #+#    #+#             */
/*   Updated: 2025/03/02 14:37:32 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <stdexcept>

// Canonicall form //
RPN::RPN() : _inputs("") { 
}
RPN::RPN(RPN const & src){
    *this = src;
}
RPN::RPN(std::string const & inputs) : _inputs(inputs) {
    
}
RPN &   RPN::operator=(RPN const & rhs){
    _inputs = rhs._inputs;
    return (*this);
}
RPN::~RPN(){}

std::string   RPN::getInputs() const{
    return (_inputs);
}

//***************Make Calcul***************//
double  RPN::makeCalcul(double x, double y, std::string op) const{
    if (op == "+") return x + y;
    if (op == "-") return x - y;
    if (op == "*") return x * y;
    if (op == "/") {
        if (y == 0){
            throw std::runtime_error("Error : Division by zero.");
        }
        return x / y;
    }
    throw std::runtime_error("Error : Invalid operator.");
    
}

//***************isOp***************//
bool    RPN::isOp(std::string op) const{
    if (op == "+" || op == "-" || op == "*" || op == "/")
        return true ;
    else
        return false;
}
    

//  Compute
double    RPN::compute() const{
    std::stack<double>  container;
    std::istringstream isst(_inputs);
    std::string token;
    while(isst >> token){

        if (!token.empty() && ( (token.size() == 1 && std::isdigit(token[0])) ||
            (token.size() == 2 && token[0] == '-' && std::isdigit(token[1]) ) ||
            (token.size() == 2 && token[0] == '+' && std::isdigit(token[1]) ) )){
            
            double num = std::atof(token.c_str());
            if (num <=-10 || num >= 10){
                throw std::runtime_error("Error: Number out of range. All numbers must be between -10 and 10.");
            }
            container.push(num);
            //std::cout << "i = " << i++ << std::endl;
        }
        else if (isOp(token))
        {
            //std::cout <<"container.size()" <<container.size()<< token << std::endl;
            if (container.size() < 2){
                throw std::runtime_error("Error: Insufficient inputs");
            }
            //else if (container.size() == 2){
                double  y = container.top();
                container.pop();
                double  x = container.top();
                container.pop();
                double result = makeCalcul(x, y, token);
                container.push(result);
                
            /*}
            else{
                throw std::runtime_error("Error: Incorrect expression");
            }*/
        }
        else {
            throw std::runtime_error("Error : incorrect expression: two many operands or operators.");
        }
    }
    if (container.size() != 1)
        throw std::runtime_error("Error : two many operands or operators");
    return container.top();

}



