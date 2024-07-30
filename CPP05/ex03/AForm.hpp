/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:39:18 by ilouacha          #+#    #+#             */
/*   Updated: 2024/07/30 18:18:08 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class AForm {
private:
	const std::string	_name;
	bool				_signed;
	const int			minSignGrade;
	const int 			minExecGrade;
public:
	
	AForm(void);
	AForm(const std::string n, const int minEG, const int minSG);
	AForm(AForm const & src);
	AForm&			operator=(AForm const & rhs);
	virtual 			~AForm(void);

	//Fonction membre
	void	beSigned(class Bureaucrat const& B);
	
	//Getteurs et setteurs
	std::string		getName() const;
	int				getMinSignGrade() const;
	int				getMinExecGrade() const;
	bool			getSign() const;
	
	virtual void	execute(Bureaucrat const & executor) const = 0;
	

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw(){
			return ("Exception : grade too high !");
		}
	};
	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw() {
			return ("Exception : grade too low !");
		}
	};
	
	class fileNotOpened : public std::exception {
		virtual const char*	what() const throw() {
			return ("Exception : Could not open the file !");
		}
	};
	class FormNotSigned : public std::exception {
		virtual const char* what() const throw(){
			return ("Exception: form not signed, can't be executed !");
		}
	};

	class OperationFailed : public std::exception {
		virtual const char* what() const throw(){
			return ("Exception : the operation failed !");
		}
	};
	
};

std::ostream&	operator<<(std::ostream& os, AForm const&f);

#endif