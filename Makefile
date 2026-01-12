NAME = so_long

SRC = main.c

GNL =	getNextLine/get_next_line_utils.c\
		getNextLine/get_next_line.c\

OBJS = ${SRC:.c=.o} ${GNL:.c=.o}

CC        = cc
RM        = rm -f
CFLAGS = -Wall -Wextra -Werror
INCS	= -I ./includes/

all:    ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@ $(INCS)

$(NAME): ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re