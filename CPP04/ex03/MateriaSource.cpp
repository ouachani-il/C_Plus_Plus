/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:16:15 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/20 16:11:49 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "IMateriaSource.hpp"
# include "MateriaSource.hpp"
# include "AMateria.hpp"

MateriaSource::MateriaSource(void) : _iLearn(0){
	
	for (int k =0; k < 4; k++){
		_materia[k] = NULL;
	}
}
MateriaSource::MateriaSource(MateriaSource const &src){
	*this = src;
}

MateriaSource::~MateriaSource(void){
	
	for (int k = 0; k < _iLearn; k++){
		if (_materia[k] != NULL)
			delete _materia[k];
	}
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs){
	_iLearn = rhs._iLearn;
	for (int k = 0 ; k < 4; k++ ){
		if ( _materia[k] != NULL)
			delete _materia[k];
		if (rhs._materia[k] != NULL) {
			_materia[k] = rhs._materia[k]->clone();
		}
		else{
			_materia[k] = NULL;
		}
	}
	return *this;
}
void		MateriaSource::learnMateria(AMateria* materia){
	if (_iLearn < 4){
		_materia[_iLearn] = materia;
		_iLearn++;
	}
	if (_iLearn == 4)
		_iLearn = 0;
}

AMateria* 	MateriaSource::createMateria(std::string const & type){
	for (int k = 0; k < 4; k++) {
		if (_materia[k] != NULL){
				if (_materia[k]->getType() == type) {
				return _materia[k]->clone(); //deep copy
				//return this->_materias[k]; // shallow copy
			}
		}
	}
	return NULL;
}
