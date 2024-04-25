/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zambie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:13:00 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/25 10:04:48 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZAMBIE_HPP_
# define _ZAMBIE_HPP_

# include <string>

class Zambie{
    public:
        Zambie(void);
        ~Zambie(void);
        void    annonce(void) const;
		Zambie*	newZambie(std::string nom);
    private:
        std::string _name;
        
};

#endif