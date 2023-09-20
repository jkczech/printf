/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:44:22 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/20 10:52:05 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	isspecifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X');
}

int	print_va(va_list args, char spec)
{
	if (spec == 'c')
		ft_putchar(va_arg(args, int));
	else if (spec == 'i' || spec == 'd')
		ft_putnbr(va_arg(args, int));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	vars;

	i = 0;
	va_start(vars, format);
	while (format[i])
	{
		if (format[i] == '%' && isspecifier(format[i + 1]))
		{
			print_va(vars, format[i + 1]);
			i++;
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(vars);
	return (0);
}
