# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/07 16:54:00 by chahan            #+#    #+#              #
#    Updated: 2022/05/07 16:54:03 by chahan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wextra -Werror -Wall -fsanitize=thread -g
CFLAGS += -g

NAME = philo

DIR_H = ./includes/
DIR_S = ./srcs/
DIR_O = ./

SRC =	ft_atoif.c \
		ft_utils.c	\
		ft_time.c	\
		ft_check.c	\
		ft_init.c	\
		ft_philo.c	\
		main.c		\

SRCS = $(addprefix $(DIR_S), $(SRC))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(OBJS) $(NAME)

re: fclean all

.PHONY: clean fclean all re
