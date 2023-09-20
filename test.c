/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:48:10 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/20 10:00:26 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	ft_printf(argv[1], argv[2]);
	printf(argv[1], argv[2]);
	return (0);
}