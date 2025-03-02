# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 10:54:02 by ilham_oua         #+#    #+#              #
#    Updated: 2025/03/01 10:54:03 by ilham_oua        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= btc

CC		= c++

HEADERS	= ./includes/BitcoinExchange.hpp 

CFLAGS	= -g -std=c++98 -Wextra -Werror -Wall 

SRCS	= main.cpp \
	./srcs/BitcoinExchange.cpp 

OBJS	= $(SRCS:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) -c $(CFLAGS) $< -o $@
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean