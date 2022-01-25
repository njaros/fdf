NAME = fdf
SRCS =	fdf.c \
		fill_lst.c \
		get_next_line_utils.c \
		get_next_line.c \
		main.c \
		parsing_map.c \
		parsing_utils.c \
		fdf_utils.c \
		fdf_utils2.c \
		tab_build.c \
		rotato.c \
		plan_build.c \
		traiteur.c \
		ft_display.c
SRCS_TEST =	fdf.c \
			plan_build.c \
			rotato.c \
			fill_lst.c \
			traiteur.c \
			get_next_line_utils.c \
			get_next_line.c \
			parsing_map.c \
			parsing_utils.c \
			fdf_utils.c \
			fdf_utils2.c \
			ft_display.c \
			tab_build.c \
			test.c
OBJS = ${SRCS:.c=.o}
OBJS_TEST =	${SRCS_TEST:.c=.o}
HEADERS = includes/fdf.h includes/libft.h includes/mlx.h includes/get_next_line.h
LIB = lib/libmlx.a lib/libft.a
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=30

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	gcc -o ${NAME} ${OBJS} ${LIB} -framework OpenGL -framework AppKit

test: ${OBJS_TEST}
	gcc -o test ${OBJS_TEST} ${LIB} -framework OpenGL -framework AppKit

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

clean_test :
	${RM} ${OBJS_TEST}

fclean_test :	clean_test
	${RM} test

re : fclean all
