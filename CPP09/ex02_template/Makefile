# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/02 10:52:34 by ilouacha          #+#    #+#              #
#    Updated: 2025/03/14 15:32:24 by ilouacha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Target = PmergeMe

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

FILES = main.cpp

objects = $(FILES:.cpp=.o)

$(Target): $(objects)
	$(CC) $(FLAGS) -o $(Target) $(objects)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: clean fclean re

clean:
	rm -f $(objects)

fclean: clean
	rm -f $(Target)

re: fclean $(Target)