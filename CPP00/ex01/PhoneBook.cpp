/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:45:51 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/16 00:36:56 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void){
     std::cout << "constructor called" << std::endl;
   
}

PhoneBook::~PhoneBook(void){
    std::cout << "Destructor called" << std::endl;
}

PhoneBook::Add(){
    
}
PhoneBook::Search(){
    
}
PhoneBook::Delete(){
	
}

int main()
{
	PhoneBook	my_phoneBook;
	Contact		old_contact;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	std::string str_index;

}

int main() {

  std::string str;

  PhoneBook phonebook;
  Contact contact;
  std::string first_name;
  std::string last_name;
  std::string nickname;
  std::string phone_number;
  std::string darkest_secret;
  std::string str_index;
  int index;
  int count = 0;
  while (!std::cin.eof()) {
    std::cin >> str;
    if (str == "ADD") {
      std::cout << "donnez le first name" << std::endl;

      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      getline(std::cin, first_name);
      std::cout << "donnez le last name" << std::endl;

      getline(std::cin, last_name);
      std::cout << "donnez le nick name" << std::endl;
      getline(std::cin, nickname);
      std::cout << "donnez le phone number" << std::endl;
      getline(std::cin, phone_number);
      while (ft_check_number(phone_number)) {
        std::cout << "Donnez un nombre valide" << std::endl;
        getline(std::cin, phone_number);
      }

      std::cout << "donnez le darket_secret" << std::endl;
      getline(std::cin, darkest_secret);
      phonebook.add(Contact(first_name, last_name, nickname, phone_number,
                            darkest_secret));
      if (count < 7)
        count++;
    } else if (str == "SEARCH") {
      phonebook.print_phone_book(count);
      if (count == 0) {
        std::cout << "phonebook vide" << std::endl;
      } else {
        std::cout << "donnez un indice valide" << std::endl;
        std::cin >> str_index;
        index = atoi(str_index.c_str());
        if (ft_check_number(str_index) || index <= 0 || index > count) {
          if (std::cin.eof())
            std::cout << "saisie vide" << std::endl;
          else
            std::cout << "indice invalid" << std::endl;
          // return ;
        } else {
          phonebook.search(index - 1).display();
        }
      }
    } else if (str == "EXIT") {
      break;
    }
  }
}