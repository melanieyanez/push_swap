# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 15:47:00 by myanez-p          #+#    #+#              #
#    Updated: 2023/04/07 17:54:17 by myanez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = main.c instr_A.c instr_B.c list_mngt.c list_mvnt.c sort_2.c sort_3.c sort_4.c sort_5.c sort_big.c sort_big_tools.c sort_tools.c arg_mngt.c err_mngt.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap

RM = rm -f

GCC = GCC

CFLAGS = -Wall -Wextra -Werror

.c.o : 
		${GCC} ${CFLAGS}  -g -c $< -o ${<:.c=.o} 

${NAME} : ${OBJS}
		make -C libft
		${GCC} -Llibft -lft -o ${NAME} ${OBJS}

all : ${NAME}

clean : 
		make clean -C libft
		${RM} ${OBJS}

fclean :	clean
			make fclean -C libft
			${RM} ${NAME}

re : fclean all

.PHONY: re fclean clean all
