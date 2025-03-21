/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:05:23 by ilouacha          #+#    #+#             */
/*   Updated: 2025/01/24 13:28:41 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int argc, char **argv) {
  if (argc == 2)
    Converter::convert(argv[1]);
  else
    std::cout << "Undefined behavior" << std::endl;

  return 0;
}
