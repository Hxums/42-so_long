NAME = so_long

SRC =	main.c \
	checker.c \
	map.c \
	utils.c \
	flood_fill.c \
	ft_grid_copy.c \
	mlx_utils.c \
	window.c \

GNL =	getNextLine/get_next_line_utils.c\
		getNextLine/get_next_line.c\

OBJS = ${SRC:.c=.o} ${GNL:.c=.o}

CC      = cc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror
INCS	= -I ./includes/ -I ./minilibx-linux/

MLX_DIR	= ./minilibx-linux
MLX_LIB	= ${MLX_DIR}/libmlx.a
MLX_LDFLAGS = -L${MLX_DIR} -lmlx -lXext -lX11 -lm -lz

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@ ${INCS}

${NAME}: ${MLX_LIB} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${MLX_LDFLAGS} -o ${NAME}

${MLX_LIB}:
	${MAKE} -C ${MLX_DIR}

clean:
	${RM} ${OBJS}
	${MAKE} -C ${MLX_DIR} clean

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re