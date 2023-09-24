/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:38:33 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/24 15:24:45 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isspecifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

int	isflag(const char *format, int *i)
{
	return (((format[*i + 1] == '+' || format[*i + 1] == ' ')
			&& (format[*i + 2] == 'd' || format[*i + 2] == 'i'))
		|| (format[*i + 1] == '#'
			&& (format[*i + 2] == 'x' || format[*i + 2] == 'X'))
		|| (format[*i + 1] == ' ' && format[*i + 2] == 's')
		|| (format[*i + 1] == ' ' && ft_isdigit(format[*i + 2])
			&& format[*i + 3] == 's'));
}

int	isskipflag(const char *format, int *i)
{
	return (isspecifier(format[*i + 2]));
}
