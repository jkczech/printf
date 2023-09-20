/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:52:20 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/20 10:00:23 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H


//malloc, free, (size_t)
# include <stdlib.h>
//write
# include <unistd.h>
//variadic funcs
# include <stdarg.h>

//extra libs for testing to delete
//printf
# include <stdio.h>

void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_printf(const char *format, ...);

//unused to delete
int		count_vars(const char *format);

#endif
