# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 15:47:00 by myanez-p          #+#    #+#              #
#    Updated: 2023/03/17 17:55:29 by melanieyane      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = main.c instr_A.c instr_B.c list_mngt.c list_mvnt.c sort_2.c sort_3.c sort_4.c sort_5.c sort_tools.c arg_mngt.c err_mngt.c utils.c
OBJS = ${SRCS:.c=.o}
NAME = push_swap
HEADERS = .

RM = rm -f

GCC = GCC

CFLAGS = -Wall -Wextra -Werror

.c.o :
		${GCC} ${CFLAGS} -I ${HEADERS} -g -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
		${GCC} ${CFLAGS} -o ${NAME} ${OBJS}

all : ${NAME}

clean : 
		${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME}

re : fclean all

.PHONY: re fclean clean all
