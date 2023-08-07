/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:05:22 by vegret            #+#    #+#             */
/*   Updated: 2023/06/27 14:05:22 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain &source);
		~Brain();
		Brain &operator=(const Brain &source);

	private:
		std::string ideas[100];
};

#endif