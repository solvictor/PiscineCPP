/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:03:23 by vegret            #+#    #+#             */
/*   Updated: 2023/06/18 17:29:10 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int value;
		const static int FRAC = 8;
	public:
		Fixed();
		Fixed(const Fixed &source);
		~Fixed();
		Fixed &operator=(const Fixed &source);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif