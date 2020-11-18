# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanisha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 11:25:42 by hanisha           #+#    #+#              #
#    Updated: 2020/11/02 16:41:36 by hanisha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

NAMES	= libft.so

SRCS =  $(shell find . -name "ft_*.c")

CC		= gcc

GFLAG	= -Wall -Wextra -Werror

FLAGSO = -shared

OBJS	= ${SRCS:.c=.o}

RM 		= rm -rf

.c.o:
	${CC} ${GFLAG} -c $< -o ${<:.c=.o}

${NAME}:    ${OBJS}
	${CC} ${GFLAG} -c ${SRCS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

so:
	${CC} ${FLAGSO} -o ${NAMES} ${OBJS}

all: ${NAME}


clean:
	 ${RM} ${OBJS}

fclean: clean
	 ${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
