OBJS		= ${SRCS:.c=.o}
NAME		= libgnl.a
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
RM			= rm -Rf
LIB			= ar rc
INC			= includes
SRCS		= get_next_line.c\
			  get_next_line_utils.c

NL_TXT			= echo ""
CHARG_LINE_TXT	= echo "$(GREEN)█$(RESET)\c"
GREEN			= \033[1;32m
RESET			= \033[0m

.c.o:
			@${CC} ${FLAGS} -I$(INC) -c $< -o ${<:.c=.o}
			@$(CHARG_LINE_TXT)

all:		${NAME}

${NAME}:	${OBJS}
			@${LIB} ${NAME} ${OBJS}
			@$(NL_TXT)

clean:
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all./

.PHONY:		all clean flcean re

