/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unused_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:49:16 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/20 09:57:09 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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



