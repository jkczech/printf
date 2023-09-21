/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:52:20 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/21 17:32:49 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

//ft_is.c
int	isdigit(char c);
int	isspecifier(char c);
int	isflag(const char *format, int *i);

//other.c
int	print_flag_va(const char *format, int *i, va_list args);
int	ft_printf(const char *format, ...);
int	ft_putchar_fd(int c, int fd);
int	ft_puthexa(int nbr, char spec);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putnbr(long long n);
int	ft_putptr(unsigned long int ptr);
int	ft_putstr_fd(char *s, int fd);
int	ft_strlen(char *str);

//unused to delete
int	count_vars(const char *format);

#endif
