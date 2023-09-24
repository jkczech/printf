/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:52:20 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/24 15:25:03 by jkoupy           ###   ########.fr       */
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

//ft_is.c
int	ft_isdigit(char c);
int	isspecifier(char c);
int	isflag(const char *format, int *i);
int	isskipflag(const char *format, int *i);

//other.c
int	print_flag_va(const char *format, int *i, va_list args);
int	ft_printf(const char *format, ...);
int	ft_putchar_fd(int c, int fd);
int	ft_puthexa(int nbr, char spec);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putnbr_fd(long long n, int fd);
int	ft_putptr_fd(unsigned long int ptr, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_strlen(char *str);

//unused to delete
int	count_vars(const char *format);

#endif
