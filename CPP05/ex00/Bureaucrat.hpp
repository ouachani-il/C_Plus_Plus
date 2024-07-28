/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:30:49 by ilouacha          #+#    #+#             */
/*   Updated: 2024/07/28 20:50:27 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat{


private:
	const std::string			name;
	int					grade;
public:
	Bureaucrat(void);
	Bureaucrat(std::string n, int g);
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat&			operator=(Bureaucrat const & rhs);
	virtual 			~Bureaucrat(void);
	
	const std::string	getName() const;
	int			getGrade() const;
	void		incGrade();
	void		decGrade();
	
	class GradeTooHighException: public std::exception{
		public:
		virtual const char* what() const throw(){
			return ("Exception : Grade too high !");
		}
	};
	class GradeTooLowException: public std::exception{
		public:
		virtual const char* what() const throw(){
			return ("Exception : Grade too low !");
		}
	};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat);

#endif