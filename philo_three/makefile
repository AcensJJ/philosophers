# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacens <jacens@student.le-101.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 14:37:19 by jacens            #+#    #+#              #
#    Updated: 2020/02/22 17:12:36 by jacens           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_two
SRCS	=	srcs/philo_two.c
HEADER  =   includes
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
OBJS	=	$(SRCS:.c=.o)

LFLAGS  =   -I $(HEADER)

%.o:		%.c $(HEADER)/philo_two.h
	$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all fclean clean re philo_one