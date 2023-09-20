/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:48:10 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/20 17:05:05 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	int	res;

	res = 0;
	res = ft_printf("%p", &res);
	printf ("\nres: %d\n", res);
	res = printf("%p", &res);
	printf ("\nres: %d\n", res);
	return (0);
}
