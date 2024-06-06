# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 16:30:21 by ilouacha          #+#    #+#              #
#    Updated: 2024/06/06 18:19:50 by ilouacha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	= $(shell find . -name "*.cpp")

OBJS	= ${SRCS:.cpp=.o}

NAME	= sedForLoosers

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