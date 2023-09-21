/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:52:20 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/21 10:35:04 by jkoupy           ###   ########.fr       */
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

int	ft_printf(const char *format, ...);
int	ft_putchar_fd(int c, int fd);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putnbr(long long n);
int	ft_putptr(unsigned long int ptr);
int	ft_putstr_fd(char *s, int fd);
int	ft_strlen(char *str);

//unused to delete
int	count_vars(const char *format);

#endif