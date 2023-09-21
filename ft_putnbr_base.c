/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:04:42 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/21 10:36:28 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int			base_num;
	int			printlen;

	printlen = 0;
	base_num = ft_strlen(base);
	if (nbr >= base_num)
	{
		printlen += ft_putnbr_base(nbr / base_num, base);
		nbr %= base_num;
	}
	if (nbr < base_num)
	{
		ft_putchar_fd(base[nbr], 1);
		printlen++;
	}
	return (printlen);
}
