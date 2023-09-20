NAME = test
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_putnbr.c ft_putchar.c test.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
