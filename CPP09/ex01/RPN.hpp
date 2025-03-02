/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:38:33 by ilouacha          #+#    #+#             */
/*   Updated: 2025/03/02 14:36:42 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <string>
#include <stack>
#include <iostream>


class RPN {
    private:
        std::string _inputs;
        std::stack<double>  _container;
        bool    isOp(std::string op) const;
        double  makeCalcul(double x, double y, std::string op) const;
    public:
        RPN();
        RPN(RPN const & src);
        RPN(std::string const & inputs);
        RPN &   operator=(RPN const & rhs);
        ~RPN();

        std::string   getInputs() const;
        
        double    compute() const;
};
#endif 