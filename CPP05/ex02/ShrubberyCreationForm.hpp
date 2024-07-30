/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:13:06 by ilouacha          #+#    #+#             */
/*   Updated: 2024/07/30 16:48:04 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <string>


class ShrubberyCreationForm : public AForm {
private:
	std::string	target;
public:

	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string t);
	ShrubberyCreationForm(ShrubberyCreationForm const& src);
	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& rhs);
	~ShrubberyCreationForm();

	//getteurs
	std::string		getTarget(void) const;

	void 			execute( Bureaucrat const & executor) const;

};

#endif