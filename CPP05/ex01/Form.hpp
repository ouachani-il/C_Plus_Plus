/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:57:02 by ilouacha          #+#    #+#             */
/*   Updated: 2024/07/29 15:09:11 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Form {
private:
	const std::string	_name;
	bool				_signed;
	const int			minSignGrade;
	const int 			minExecGrade;
public:
	
	Form(void);
	Form(const std::string n, const int minEG, const int minSG);
	Form(Form const & src);
	Form&			operator=(Form const & rhs);
	virtual 			~Form(void);

	//Fonction membre
	void	beSigned(class Bureaucrat const& B);
	
	//Getteurs et setteurs
	std::string		getName() const;
	int				getMinSignGrade() const;
	int				getMinExecGrade() const;
	bool			getSign() const;
	
	

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
	
};

std::ostream&	operator<<(std::ostream& os, Form const&f);

#endif