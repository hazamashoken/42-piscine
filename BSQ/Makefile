# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 03:49:49 by tliangso          #+#    #+#              #
#    Updated: 2022/06/28 14:04:03 by tliangso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRLIB		= libft/

LIBFT		= ft_atoi.c ft_putchar.c ft_putstr.c ft_strdup.c ft_strlen.c ft_putnbr.c  

DIRSRC		= srcs/

SRC			= main.c freezero.c map.c map2.c solution.c solve_map.c  ${addprefix ${DIRLIB}, ${LIBFT}}

SRCS		= ${addprefix ${DIRSRC}, ${SRC}}

OBJS		= ${SRCS:.c=.o}

HEAD		= includes/

NAME		= bsq

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS} ${CFLAGS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
