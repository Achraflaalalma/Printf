
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rc
PRINTF = ft_printf.h

SRCS =	ft_printf.c ft_putchar.c ft_puthex.c  ft_putnbr.c \
		ft_putstr.c ft_uputnbr.c ft_puthexp.c

OBJ = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)
	@echo "Compiled"
	

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c $(PRINTF)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaned"
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean