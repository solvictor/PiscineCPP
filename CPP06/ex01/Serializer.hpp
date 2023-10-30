/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:55:20 by vegret            #+#    #+#             */
/*   Updated: 2023/10/26 22:58:24 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <string>
# include <stdint.h>

struct Data
{
	std::string	name;
	int			age;
};

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer &source);
		~Serializer();
		Serializer &operator=(const Serializer &source);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif