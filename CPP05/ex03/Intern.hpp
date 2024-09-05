/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:40:14 by ilouacha          #+#    #+#             */
/*   Updated: 2024/08/01 16:14:12 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern {
public:
	Intern(void);
	Intern(Intern const& src);
	Intern&	operator=(Intern const& rhs);
	~Intern();

	AForm*	makeForm(std::string formName, std::string targetName);

	class formNotFound : public std::exception {
		public:
		const char* what() const throw() {
			return "Exception : form type not found !";
		}
	};
};
#endif // !INTERN_HPP
