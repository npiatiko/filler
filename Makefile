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
SRCS = search_place.c \
       piece.c \
       main.c \
       calc_distmap.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	make -C libft/
	$(CC) $(FLAGS) -c $(SRCS)
	$(CC) $(OBJS) -o $(NAME) -L libft/ -lft

$(LIBFT):
	make -C libft/

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C libft/ clean
	rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all