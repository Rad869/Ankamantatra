# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 10:52:34 by rrabeari          #+#    #+#              #
#    Updated: 2024/06/25 10:24:45 by bhamed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      := hackamantatra

CC        := gcc
CFLAGS    := -Wall -Werror -Wextra

SRCS      := sources/main.c \
             sources/get_next_line/get_next_line.c \
             sources/get_next_line/get_next_line_utils.c \
             sources/play.c \
             sources/utils.c

OBJS      := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
