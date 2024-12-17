/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:05:23 by ilouacha          #+#    #+#             */
/*   Updated: 2024/12/17 14:10:07 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"
#include <iomanip>
#include <ios>
int main(int argc, char **argv) {
  if (argc == 2)
    ScalarConvert::converter(argv[1]);
  else
    std::cout << "Undefined behavior" << std::endl;

  return 0;
}
