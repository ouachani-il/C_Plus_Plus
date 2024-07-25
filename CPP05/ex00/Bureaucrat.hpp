/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:30:49 by ilouacha          #+#    #+#             */
/*   Updated: 2024/07/25 23:34:52 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
#

class Bureaucrat{
private:
	std::string			name;
	int					grade;
public:
	Bureaucrat(void);
	//Bureaucrat(std::string n, int g);
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat&			operator=(Bureaucrat const & rhs);
	virtual 			~Bureaucrat(void);
	
	std::string	getName();
	int			getGrade();
	void		incGrade();
	void		decGrade();
	void		GradeTooHighException();
	void		GradeTooLowException();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif