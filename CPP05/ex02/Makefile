# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/28 19:58:34 by ilouacha          #+#    #+#              #
#    Updated: 2024/08/01 17:58:22 by ilouacha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(shell find . -name "*.cpp")

OBJS	= ${SRCS:.cpp=.o}

HEADERS = $(shell find . -name "*.hpp")

NAME	= form

CC		= c++

CFLAGS	= -Wall -Werror -Wextra -std=c++98 -g

RM		= rm -rf

.cpp.o:
		${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

all:	$(NAME)

$(NAME): ${OBJS} ${HEADERS}
		${CC} ${CFLAGS} ${OBJS}  -o ${NAME}

clean:	
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all re clean fclean
