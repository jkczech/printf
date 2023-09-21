/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:36:35 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/21 12:26:24 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_ptr(unsigned long int nbr)
{
	unsigned long int	base_num;
	int					printlen;
	char				*base;

	printlen = 0;
	base = "0123456789abcdef";
	base_num = ft_strlen(base);
	if (nbr >= base_num)
	{
		printlen += ft_putnbr_ptr(nbr / base_num);
		nbr %= base_num;
	}
	if (nbr < base_num)
	{
		ft_putchar_fd(base[nbr], 1);
		printlen++;
	}
	return (printlen);
}

int	ft_putptr(unsigned long int ptr)
{
	int	printlen;

	if (ptr == 0)
		return (ft_putstr_fd("(nil)", 1));
	printlen = 0;
	printlen += ft_putstr_fd("0x", 1);
	printlen += ft_putnbr_ptr(ptr);
	return (printlen);
}
