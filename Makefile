NAME = ft_ssl
SRC =   srcs/main.c \
        srcs/ft_ssl_md5.c

OBJ = $(SRC:.cpp=.o)
CXX = cc
CXXFLAGS = -Wall -Wextra -Werror -g

MAKEFLAGS += --silent -j

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	echo "build done."

clean:
	@rm -f $(OBJ)
	echo "object(s) cleaned."

fclean: clean
	@rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
	$(MAKE) clean
.PHONY: all clean fclean re