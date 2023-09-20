/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:04:42 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/20 17:06:38 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(long long nbr, char *base)
{
	long long	nbr_cpy;
	int			base_num;
	int			printlen;

	nbr_cpy = nbr;
	printlen = 0;
	if (!valid_base(base))
		return (0);
	base_num = ft_strlen(base);
	if (nbr_cpy < 0)
	{
		ft_putchar_fd('-', 1);
		printlen++;
		nbr_cpy = -nbr_cpy;
	}
	if (nbr_cpy >= base_num)
	{
		printlen += ft_putnbr_base(nbr_cpy / base_num, base);
		nbr_cpy %= base_num;
	}
	if (nbr_cpy < base_num)
	{
		ft_putchar_fd(base[nbr_cpy], 1);
		printlen++;
	}
	return (printlen);
}
