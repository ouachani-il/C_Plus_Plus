# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 11:10:14 by ilouacha          #+#    #+#              #
#    Updated: 2024/05/28 23:01:48 by ilham_oua        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(shell find . -name "*.cpp")

OBJS	= ${SRCS:.cpp=.o}

NAME	= ClapTrap

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