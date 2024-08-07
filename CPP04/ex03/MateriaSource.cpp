/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:16:15 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/23 20:25:33 by ilouacha         ###   ########.fr       */
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
	
	for (int k = 0; k < 4; k++){
		if (_materia[k] != NULL)
		{
			delete _materia[k];
		}
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

/**************************METHOD*****************************/

void		MateriaSource::learnMateria(AMateria* materia){
	if (materia == NULL)
		return ;
	for (int k = 0; k < 4; k++){
		if (this->_materia[k] == NULL){
			this->_materia[k] = materia;
			return ;
		}
	} 
	/*if (this->_iLearn < 4){
		this->_materia[_iLearn] = materia;
		this->_iLearn++;
	}
	if (this->_iLearn == 4)
		this->_iLearn = 0;*/
}

AMateria* 	MateriaSource::createMateria(std::string const & type){
	for (int k = 0; k < 4; k++) {
		if (_materia[k] != NULL)
		{
			//std::cout << _materia[k]->getType() << " == " << type << std::endl;
			if (_materia[k]->getType() == type)
			{
				return this->_materia[k]->clone(); //deep copy
				//return this->_materia[k]; // shallow copy
			}
		}
	}

	return NULL;
}
