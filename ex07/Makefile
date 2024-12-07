NAME	= matrix

CC		= c++ -Wall -Wextra -Werror -std=c++20

RM		= rm -rf

SRCS	= main.cpp

OBJS	= ${SRCS:.c=.o}

all: 	${NAME}
  
%.o:	%.c
		${CC} -c $< -o $@

${NAME}:	${OBJS}
		${CC} -o ${NAME} ${OBJS}

clean:
		${RM} ${SRCS:.cpp=.o}

fclean:		clean
		${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re