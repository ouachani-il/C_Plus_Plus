/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:30:49 by ilouacha          #+#    #+#             */
/*   Updated: 2024/07/26 18:06:59 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat{
	class GradeTooHighException: public std::exception{
		public:
		virtual const char* what() const throw(){
			return ("Grade too high !");
		}
	};
	class GradeTooLowException: public std::exception{
		public:
		virtual const char* what() const throw(){
			return ("Grade too low !");
		}
	};


private:
	const std::string			name;
	int					grade;
public:
	Bureaucrat(void);
	Bureaucrat(std::string n, int g);
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat&			operator=(Bureaucrat const & rhs);
	virtual 			~Bureaucrat(void);
	
	std::string	getName();
	int			getGrade();
	void		incGrade();
	void		decGrade();
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat);

#endif