NAME = so_long

SRC =	src/main.c \
	src/checker.c \
	src/map.c \
	src/utils.c \
	src/flood_fill.c \
	src/mlx_utils.c \
	src/window.c \
	src/player.c \
	src/sprites.c \
	src/ft_itoa.c \
	src/game.c \
	src/animation.c \

GNL =	getNextLine/get_next_line_utils.c\
		getNextLine/get_next_line.c\

OBJS = ${SRC:.c=.o} ${GNL:.c=.o}

CC      = cc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror

MLX_DIR	= ./minilibx-linux
MLX_LIB	= ${MLX_DIR}/libmlx.a
MLX_LDFLAGS = -L${MLX_DIR} -lmlx -lXext -lX11 -lm -lz

PRINTF_DIR = ./printf
PRINTF_LIB = ${PRINTF_DIR}/libftprintf.a

GNL_DIR = ./getNextLine

INCS	= -I ./includes/ -I ${MLX_DIR} -I ${PRINTF_DIR} -I ${GNL_DIR}

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@ ${INCS}

${NAME}: ${MLX_LIB} ${PRINTF_LIB} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${MLX_LDFLAGS} ${PRINTF_LIB} -o ${NAME}

${MLX_LIB}:
	${MAKE} -C ${MLX_DIR}

${PRINTF_LIB}:
	${MAKE} -C ${PRINTF_DIR}

clean:
	${RM} ${OBJS}
	${RM} getNextLine/*.o
	${MAKE} -C ${MLX_DIR} clean
	${MAKE} -C ${PRINTF_DIR} clean

fclean: clean
	${RM} ${NAME}
	${MAKE} -C ${PRINTF_DIR} fclean


re: fclean all

.PHONY: all clean fclean re