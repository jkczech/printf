/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:48:10 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/21 17:47:14 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{

	char c = 0;
    char *str = 0;
    int d = 0;
    unsigned int u = 0;
    int x = 0;
    int X = 0;

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
	res = ft_printf("a% s a", "");
	printf ("\nReturn value: %d\n", res);
	res = printf("a% s a", "");
	printf ("\nReturn value: %d\n", res);
	return (0);
}
