# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 15:47:00 by myanez-p          #+#    #+#              #
#    Updated: 2023/09/07 12:08:39 by melanieyane      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Dossiers

SRCDIR = srcs
OBJDIR = objs
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
	@echo "\nCompiling the libft library..."
	@if [ ! -f libft/libft.a ]; then make -C libft; fi
	@echo "\nCompiling push_swap executable..."
	@${GCC} ${CFLAGS} -I ${HEADERS} ${OBJS} -Llibft -lft -o ${NAME}
	@echo "\nAll done!"

${OBJDIR}/%.o : ${SRCDIR}/%.c
	@${MKDIR} -p ${OBJDIR}
	@echo "Compiling $< into ${@F}..."
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
