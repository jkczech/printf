# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 10:10:19 by jkoupy            #+#    #+#              #
#    Updated: 2023/09/24 15:00:30 by jkoupy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END = \033[0m
RED = \033[31m
GREEN = \033[32m

NAME = libftprintf.a
RM = rm -rf
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
LIBFT = libft/libft.a
SRCS = ft_is.c ft_print_flag.c ft_printf.c ft_putnbr_base.c ft_putptr.c


OBJS = $(SRCS:.c=.o)

all:	$(LIBFT) $(NAME)

%.o:	%.c
	@$(CC) -c $(CFLAGS) $< -o $@

bonus:	all


$(NAME):	$(OBJS) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✅ $(NAME) created$(END) ✅"

$(LIBFT):
	@make bonus -sC libft
	@echo "$(GREEN)✅ $(LIBFT) created$(END) ✅"

clean:
	@$(RM) $(OBJS)
	@make clean -sC libft
	@echo "$(RED)🗑️  object files removed  🗑️$(END)"

fclean: clean
	@$(RM) $(NAME)
	@make -s fclean -C libft
	@echo "$(RED)🗑️  $(NAME) removed 🗑️$(END)"

re: fclean all

.PHONY: all clean fclean re bonus
