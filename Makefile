# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 10:10:19 by jkoupy            #+#    #+#              #
#    Updated: 2023/09/21 13:39:16 by jkoupy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_is.c ft_printf.c ft_putchar_fd.c ft_putnbr_base.c ft_putnbr.c \
	   ft_putptr.c ft_putstr_fd.c ft_strlen.c test.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	make clean
##del clean

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
