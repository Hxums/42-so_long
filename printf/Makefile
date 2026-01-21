NAME = libftprintf.a

SRC = ft_putnbr_base.c \
ft_printf.c \
ft_putnbr.c \
ft_strlen.c \
ft_putstr.c \
ft_print_args.c \

OBJS = ${SRC:.c=.o}

CC        = cc
RM        = rm -f
CFLAGS = -Wall -Wextra -Werror

all:    ${NAME}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -I includes ${HEADER} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re 
