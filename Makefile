# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 10:10:19 by jkoupy            #+#    #+#              #
#    Updated: 2023/09/24 13:35:13 by jkoupy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m

NAME = libftprintf.a
RM = rm -rf
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
LIBFT = libft/libft.a
SRCS = ft_is.c ft_print_flag.c ft_printf.c ft_putnbr_base.c \
	   ft_putnbr.c ft_putptr.c ft_strlen.c


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
	@echo "$(RED)🗑️  Object files removed  🗑️$(END)"

fclean: clean
	@$(RM) $(NAME)
	@make -s fclean -C libft
	@echo "$(RED)🗑️  $(NAME) removed 🗑️$(END)"

re: fclean all

.PHONY: all clean fclean re bonus
