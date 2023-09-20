/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:36:35 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/20 17:05:47 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putptr(unsigned long long ptr)
{
	int	printlen;

	ft_putstr_fd("0x", 1);
	printlen = 2;
	printlen += ft_putnbr_base(ptr, "0123456789abcdef");
	return (printlen);
}
