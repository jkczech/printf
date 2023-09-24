/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:32:05 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/24 14:13:24 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(long long n, int fd)
{
	int	printlen;

	printlen = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		printlen++;
		n = -n;
	}
	if (n >= 10)
	{
		printlen += ft_putnbr_fd(n / 10, fd);
		n %= 10;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		printlen++;
	}
	return (printlen);
}
