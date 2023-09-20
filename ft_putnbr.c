/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:48:13 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/20 16:47:08 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int n)
{
	long long	nn;
	int			printlen;

	nn = n;
	printlen = 0;
	if (nn < 0)
	{
		ft_putchar_fd('-', 1);
		printlen++;
		nn = -nn;
	}
	if (nn >= 10)
	{
		printlen += ft_putnbr(nn / 10);
		nn %= 10;
	}
	if (nn < 10)
	{
		ft_putchar_fd(nn + '0', 1);
		printlen++;
	}
	return (printlen);
}
