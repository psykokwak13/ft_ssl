NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

SRCS = ft_printf.c \
		ft_print_str.c \
		ft_print_hexa.c \
		ft_print_unsigned.c \
		ft_print_pointer.c \
		ft_print_char.c \
		ft_print_int.c \

OBJS = $(SRCS:.c=.o)

MAKEFLAGS += --silent -j

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re