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

SRCS =  ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c\
        		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
        		ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
        		ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c\
        		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
        		ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_strjoin.c\
        		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
        		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
        		ft_substr.c ft_tolower.c ft_toupper.c

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
