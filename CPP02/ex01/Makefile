# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 11:10:14 by ilouacha          #+#    #+#              #
#    Updated: 2024/05/17 12:48:37 by ilouacha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(shell find . -name "*.cpp")

OBJS	= ${SRCS:.cpp=.o}

NAME	= Fixed

CC		= clang++

CFLAGS	= -O0 -g -Wall -Werror -Wextra -std=c++98

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