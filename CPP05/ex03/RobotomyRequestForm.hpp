/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:41:49 by ilouacha          #+#    #+#             */
/*   Updated: 2024/07/30 16:35:51 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class RobotomyRequestForm : public AForm {
	
public:
	std::string	target;

	RobotomyRequestForm();
	RobotomyRequestForm(std::string t);
	RobotomyRequestForm(RobotomyRequestForm const& src);
	RobotomyRequestForm&	operator=(RobotomyRequestForm const& rhs);
	~RobotomyRequestForm();

	//getteurs
	std::string		getTarget(void) const;

	void 			execute( Bureaucrat const & executor) const;

};

#endif