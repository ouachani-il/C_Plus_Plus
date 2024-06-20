/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:34:48 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/20 17:11:43 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ICharacter.hpp"
# include "Character.hpp"
# include "AMateria.hpp"


Character::Character(void){
}

Character::Character(std::string const &name){
	_name = name;
	_iEquip = 0;
	for(int k = 0; k < 4; k++){
		_inv[k] = NULL;
	}
}

Character::Character(Character const &src){
	*this = src;
}

Character::~Character(void){
	for (int k = 0; k < _iEquip; k++){
		delete _inv[k];
	}
}
Character	&Character::operator=(Character const &rhs){
	if (this != &rhs){
		_name = rhs.getName();
		_iEquip = rhs._iEquip;
		for (int k = 0; k < 4; k++){
			//this->_inv[k] = rhs._inv[k]; // shallow copy
			this->_inv[k] = rhs._inv[k]->clone();// deep copy
		}
	}
	return *this;
}
/**************************METHOD*****************************/

std::string const & Character::getName() const{
	return (_name);
}

void Character::equip(AMateria* m) {
	if (this->_iEquip < 4){
		this->_inv[_iEquip] = m;
		//std::cout << " The " << (std::string) m->getType() << "is added to the location" << (int) _iEquip << "of the inventary" << std::endl;
		this->_iEquip++;
	std::cout <<"iEquip =" << _iEquip <<std::endl;
	}
	else if (_iEquip >=4 || _iEquip < 0){
		std::cout << "The inventary is full" << std::endl;
	}
}

void Character::unequip(int idx) {
	std::cout <<"in unequi iEquip =" << _iEquip <<std::endl;
	if (idx >= 0 && idx < 4){
		if (_inv[idx] != NULL){
			//delete _inv[idx];
			std::cout << "You just take off the materia \"" << this->_inv[idx]->getType() << "\" to the location " << idx << " of your invotery\n";;
			for (int k = idx; k < _iEquip - 1; k++){
				_inv[k] = _inv[k + 1];
			}
			_inv[_iEquip] = NULL;
			_iEquip--;
			return ;
		}
		else{
			std::cout << "Unequip is not possible : the location is empty !" << std::endl;
		}
		return ;
	}
	std::cout << "Unequip is not possible !: the index doesn't exist !" << std::endl;
}
void Character::use(int idx, ICharacter& target){
	std::cout << "in use iEquip =" << _iEquip <<"idx = " << idx << std::endl;
	if (idx >= 0 && idx < 4 && _inv[idx] != NULL){
		_inv[idx]->use(target);
	}
	else if (idx < 0 || idx >= 4){

		std::cout << "wrong inventary index" << std::endl;
	}
	else{
		std::cout << "no materia in this inventary location" << std::endl;
	}
}

