/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:48:13 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/21 10:37:03 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long n)
{
	int			printlen;

	printlen = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		printlen++;
		n = -n;
	}
	if (n >= 10)
	{
		printlen += ft_putnbr(n / 10);
		n %= 10;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', 1);
		printlen++;
	}
	return (printlen);
}
