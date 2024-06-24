# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 10:52:34 by rrabeari          #+#    #+#              #
#    Updated: 2024/06/24 11:02:35 by rrabeari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=Ankamantatra

SRC= get_next_line_utils.c \
	get_next_line.c \
	main.c \

CFLAGS = -Wall -Werror -Wextra

CC = gcc

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)
	
fclean : clean
	rm -rf $(NAME)