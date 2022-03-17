SRCS	= check_everything.c push_swap_utils.c push_swap_utils2.c main.c  \
		ft_movements.c ft_sort.c ft_sort_345.c get_list.c \
		ft_sort_big_stack.c ft_sort_100.c \
		

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

LIBFT = libft/libft.a

PATHLIB = libft/

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${LIBFT} ${OBJS}
				${CC} ${CFLAGS} ${LIBFT} ${OBJS} -o ${NAME}

${LIBFT}:
			@make -C ${PATHLIB}

all:		${NAME}

clean:
				@make clean -C ${PATHLIB}
				${RM} ${OBJS} ${OBJB}

fclean: 	clean
				@make fclean -C ${PATHLIB}
				${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re