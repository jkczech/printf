/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:44:22 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/21 13:41:27 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_simple_va(va_list args, char spec)
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
	return (printlen);
}

int	print_flag_va(const char *format, int *i, va_list args)
{
	int	printlen;
	int	num;

	printlen = 0;
	if ((format[*i + 1] == '+' || format[*i + 1] == ' ')
		&& (format[*i + 2] == 'd' || format[*i + 2] == 'i'))
	{
		num = va_arg(args, int);
		if (num >= 0)
			printlen += ft_putchar_fd(format[*i + 1], 1);
		printlen += ft_putnbr(num);
	}
	else if (format[*i + 1] == '#'
		&& (format[*i + 2] == 'x' || format[*i + 2] == 'X'))
	{
		num = va_arg(args, int);
		printlen += ft_putchar_fd('0', 1);
		printlen += ft_putchar_fd(format[*i + 2], 1);
		if (format[*i + 2] == 'X')
			printlen += ft_putnbr_base(num, "0123456789ABCDEF");
		else
			printlen += ft_putnbr_base(num, "0123456789abcdef");
	}
	*i += 2;
	return (printlen);
}

int	read_va(const char *format, int *i, va_list args)
{
	int	printlen;

	printlen = 0;
	if (isflag(format, i))
		printlen += print_flag_va(format, i, args);
	else
		printlen += print_simple_va(args, format[*i + 1]);
	if (isspecifier(format[*i + 1]))
		(*i)++;
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
			printlen += read_va(format, &i, vars);
		else
			printlen += write(1, &format[i], 1);
		i++;
	}
	va_end(vars);
	return (printlen);
}
