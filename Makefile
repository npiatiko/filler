#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/08 10:57:33 by npiatiko          #+#    #+#              #
#    Updated: 2019/02/08 10:57:34 by npiatiko         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = npiatiko.filler
FLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS = calc_distmap.c \
       main.c \
       piece.c \
       search_place.c

OBJS = $(SRCS:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(OBJS) -o $(NAME) -L libft/ -lft

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

lib:
	make -C libft/

clean:
	make -C libft/ clean
	rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all