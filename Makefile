# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 15:47:00 by myanez-p          #+#    #+#              #
#    Updated: 2023/04/08 15:29:37 by myanez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Dossiers

SRCDIR = srcs
OBJDIR = objs/
HDRDIR = includes

# Fichiers

SRCS = $(shell find ${SRCDIR} -name '*.c')
OBJS = ${SRCS:${SRCDIR}%.c=${OBJDIR}%.o}
HEADERS = ${HDRDIR}
NAME = push_swap

# Compilation

GCC = GCC
CFLAGS = -Wall -Wextra -Werror

# Commandes

MKDIR = mkdir
RM = rm -Rf

# Règles

all : ${NAME}

${NAME} : ${OBJS}
	@${GCC} ${CFLAGS} -I ${HEADERS} ${OBJS} -Llibft -lft -o ${NAME}

${OBJDIR}%.o : ${SRCDIR}%.c
	@${MKDIR} -p ${OBJDIR}
	@if [ ! -f libft/libft.a ]; then make -C libft; fi
	@${GCC} ${CFLAGS} -I ${HEADERS} -c $< -o $@

# Nettoyage

clean : 
		@make clean -C libft
		@${RM} ${OBJS}
		@${RM} ${OBJDIR}

fclean :	clean
			@make fclean -C libft
			@${RM} ${NAME}

# Autres règles

re : fclean all

.PHONY: re fclean clean all
