NAME = libft-complete.a
LIB_PRINTF = ft_printf/libftprintf.a
LIB_LIBFT = libft/libft.a

all : ${NAME}

RM = rm -f

MAKEFLAGS += --silent -j

${NAME} : ${LIB_PRINTF} ${LIB_LIBFT}
	@ar rcs ${NAME} ft_printf/*.o libft/*.o

${LIB_PRINTF} :
	${MAKE} -s -C $$(dirname $@)

${LIB_LIBFT} :
	${MAKE} -s -C $$(dirname $@)

clean :
	${MAKE} clean -s -C $$(dirname ${LIB_PRINTF});
	${MAKE} clean -s -C $$(dirname ${LIB_LIBFT});

fclean : clean
	${MAKE} fclean -s -C $$(dirname ${LIB_PRINTF});
	${MAKE} fclean -s -C $$(dirname ${LIB_LIBFT});
	# ${RM} ${LIB_PRINTF} ${LIB_LIBFT} ${NAME}
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
