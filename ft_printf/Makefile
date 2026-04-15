CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = .
INCDIR = .

SRCS = ft_printf.c non_pointer_utils.c hex_pointer_utils.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_strlen.c
OBJFILES = $(SRCS:.c=.o)
HEADER = ft_printf.h

NAME = libftprintf.a

all: $(NAME)

$(NAME) : $(OBJFILES)
	ar rc $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
