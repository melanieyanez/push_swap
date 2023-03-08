# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 15:47:00 by myanez-p          #+#    #+#              #
#    Updated: 2023/03/08 16:34:21 by myanez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = main.c push_swap_new.c push_swap_instructions.c sort_2.c sort_3.c sort_4.c sort_5.c
OBJS = ${SRCS:.c=.o}
NAME = push_swap
HEADERS = .

RM = rm -f

GCC = GCC

CFLAGS = -Wall -Wextra -Werror

.c.o :
		${GCC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
		${GCC} ${CFLAGS} -o ${NAME} ${OBJS}

all : ${NAME}

clean : 
		${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME}

re : fclean all

.PHONY: re fclean clean all
