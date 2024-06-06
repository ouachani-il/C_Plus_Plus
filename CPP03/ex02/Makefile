# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 11:04:54 by ilouacha          #+#    #+#              #
#    Updated: 2024/06/07 00:05:44 by ilham_oua        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(shell find . -name "*.cpp")

OBJS	= ${SRCS:.cpp=.o}

NAME	= FragTrap

CC		= c++

CFLAGS	= -g -Wall -Werror -Wextra -std=c++98

RM		= rm -rf

.cpp.o:
		${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

all:	$(NAME)

$(NAME): ${OBJS}	
		${CC} ${CFLAGS} ${OBJS}  -o ${NAME}

clean:	
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all re clean fclean