/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:48:10 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/21 12:28:12 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{

	char c = 'A';
    char *str = "Hello, world!";
    int d = 42;
    unsigned int u = 123;
    int x = 0x1A3F;
    int X = 0xABCD;

/*
	char c = NULL;
    char *str = NULL;
    int d = NULL;
    unsigned int u = NULL;
    int x = NULL;
    int X = NULL;
*/
	int	res;

	res = 0;
	res = ft_printf("%c %s %p %d %i %u %x %X %%\n", c, str, str, d, d, u, x, X);
	printf ("Return value: %d\n", res);
	res = printf("%c %s %p %d %i %u %x %X %%\n", c, str, str, d, d, u, x, X);
	printf ("Return value: %d\n", res);
	return (0);
}
