/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:44:22 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/21 09:47:40 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isspecifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X');
}

int	print_va(va_list args, char spec)
{
	int	printlen;

	printlen = 0;
	if (spec == 'c')
		printlen += ft_putchar_fd(va_arg(args, int), 1);
	else if (spec == 'i' || spec == 'd')
		printlen += ft_putnbr(va_arg(args, int));
	else if (spec == 's')
		printlen += ft_putstr_fd(va_arg(args, char *), 1);
	else if (spec == 'p')
		printlen += ft_putptr(va_arg(args, unsigned long long));
	else if (spec == 'u')
		printlen += ft_putnbr(va_arg(args, unsigned int));
	else if (spec == 'x')
		printlen += ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	else if (spec == 'X')
		printlen += ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
	else if (spec == '%')
		printlen += ft_putchar_fd('%', 1);
	else
		printlen += ft_putstr_fd("invalid specifier", 2);
	return (printlen);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	vars;
	int		printlen;

	i = 0;
	printlen = 0;
	if (!format || format[0] == '\0')
		return (-1);
	va_start(vars, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			printlen += print_va(vars, format[i + 1]);
			i++;
		}
		else
			printlen += write(1, &format[i], 1);
		i++;
	}
	va_end(vars);
	return (printlen);
}
