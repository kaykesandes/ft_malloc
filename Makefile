NAME = malloc.a

SRC = ft_malloc.c	ft_bestfit.c ft_free.c\

OBJS = ${SRC:.c=.o}
CC = cc
CFLAG = -Wall -Wextra -Werror
HEADER = malloc.h 
MAIN = main 
TEST_FOLDER = test 

all: ${NAME}

${NAME}: ${OBJS} ${HEADER}
	ar	-rcs ${NAME} ${OBJS}
.c.o:
	${CC} ${CFLAG} -c $< -o ${<:.c=.o}
clean:
	${RM} ${OBJS} malloc.so  *.out
fclean: clean
	${RM} ${NAME}
re: fclean all

.PHONY: clean all fclean re