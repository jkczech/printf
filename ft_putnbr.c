/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:48:13 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/20 11:28:57 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int n)
{
	long long	nn;

	nn = n;
	if (nn < 0)
	{
		ft_putchar_fd('-', 1);
		nn = -nn;
	}
	if (nn >= 10)
	{
		ft_putnbr(nn / 10);
		nn %= 10;
	}
	if (nn < 10)
		ft_putchar_fd(nn + '0', 1);
}
