/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:44:22 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/20 08:36:40 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	isspecifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X');
}

/*
int	count_vars(const char *format)
{
	int	i;
	int	count;

	i = 0;
	count = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				i += 2;
				continue ;
			}
			else if (isspecifier(format[i + 1]))
			{
				count++;
				i++;
			}
		}
		i++;
	}
	return (count);
}
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long long	nn;

	nn = n;
	if (nn < 0)
	{
		ft_putchar('-');
		nn = -nn;
	}
	if (nn >= 10)
	{
		ft_putnbr(nn / 10);
		nn %= 10;
	}
	if (nn < 10)
		ft_putchar(nn + '0');
}

int	print_va(va_list args, char spec)
{
	if (spec == 'c')
		ft_putchar(va_arg(args, int));
	else if (spec == 'i')
		ft_putnbr(va_arg(args, int));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		va_count;
	va_list	vars;

	i = 0;
/*	va_count = count_vars(format);
	printf("Variable count: %d\n", va_count);*/
	va_start(vars, format);
	while (format[i])
	{
		if (format[i] == '%' && isspecifier(format[i + 1]))
		{
			print_va(vars, format[i + 1]);
		}
		else
		{
			write(1, &format[i], 1);
			i++;
		}
	}
	va_end(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	ft_printf(argv[1], argv[2]);
	return (0);
}
