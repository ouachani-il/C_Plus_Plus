/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:45:28 by ilouacha          #+#    #+#             */
/*   Updated: 2024/07/30 16:30:09 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class PresidentialPardonForm : public AForm {
	
public:
	std::string	target;

	PresidentialPardonForm();
	PresidentialPardonForm(std::string t);
	PresidentialPardonForm(PresidentialPardonForm const& src);
	PresidentialPardonForm&	operator=(PresidentialPardonForm const& rhs);
	~PresidentialPardonForm();

	//getteurs
	std::string		getTarget(void) const;

	void 			execute( Bureaucrat const & executor) const;

};

#endif