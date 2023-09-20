/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:52:20 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/20 16:07:36 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

//size_t
# include <stddef.h>
//malloc, free
# include <stdlib.h>
//write
# include <unistd.h>
//variadic funcs
# include <stdarg.h>

//extra libs for testing to delete
//printf
# include <stdio.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_fd(int c, int fd);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putnbr(int n);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *str);

//unused to delete
int		count_vars(const char *format);

#endif
