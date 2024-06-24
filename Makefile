# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 10:52:34 by rrabeari          #+#    #+#              #
#    Updated: 2024/06/24 12:28:39 by bhamed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      := ankamantatra

CC        := gcc
CFLAGS    := -Wall -Werror -Wextra

SRC_DIR   := sources

SRC_FILES := main.c \
             get_next_line/get_next_line.c \
             get_next_line/get_next_line_utils.c

OBJ_DIR   := objs

OBJS      := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ echo ''
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ mkdir -p `dirname $@`
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@ rm -Rf $(OBJ_DIR)/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
