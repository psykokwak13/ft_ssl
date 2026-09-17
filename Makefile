NAME = ft_ssl
SRC =   srcs/main.c \
        srcs/ft_ssl_md5.c \
        srcs/ft_ssl_sha256.c \
        srcs/utils.c \
        srcs/ft_ssl.c \
        srcs/print_debug.c

OBJ         = $(SRC:.c=.o)
CXX         = cc
LIBFT_DIR   = srcs/libft-complete
LIBFT       = $(LIBFT_DIR)/libft-complete.a
CXXFLAGS    = -Wall -Wextra -Werror -I$(LIBFT_DIR) -g

MAKEFLAGS += --silent -j

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -L$(LIBFT_DIR) -lm -lft-complete -o $(NAME)
	echo "build done."

$(LIBFT):
	make -j --silent -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ) && make -j -s -C $(LIBFT_DIR) clean
	echo "object(s) cleaned."

fclean: clean
	@rm -f $(NAME) && make -j -s -C $(LIBFT_DIR) fclean

re:
	$(MAKE) fclean
	$(MAKE) all
	$(MAKE) clean
.PHONY: all clean fclean re