# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/05 12:40:55 by ilouacha          #+#    #+#              #
#    Updated: 2024/09/05 12:44:13 by ilouacha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Converter

SRCS	= $(shell find . -name "*.cpp")

OBJS	= ${SRCS:.cpp=.o}

HEADERS = $(shell find . -name "*.hpp")


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
