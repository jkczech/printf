/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:38:33 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/21 17:38:09 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

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
		|| (format[*i + 1] == ' ' && isdigit(format[*i + 2])
			&& format[*i + 3] == 's'));
}
