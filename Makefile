# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 13:38:48 by eribeiro          #+#    #+#              #
#    Updated: 2022/01/27 14:04:35 by eribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER  = push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS =		changelist.c \
			ft_atoi.c	\
			main.c \
			mouv.c\
			smallcase.c\
			smallcase2.c\
			sort_list.c\
			split.c \
			utils.c \
			utils2.c \
			check.c \
			filla.c\
			fillb.c \
			parsing.c\
			parsing2.c\
		
OBJECTS  =  ${SRCS:.c=.o}

INCLUDES =  ./

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
		$(CC) $(FLAGS) -I$(INCLUDES) $(OBJECTS) -o $(NAME)

clean:
		/bin/rm -f $(OBJECTS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

phony : all re fclean clean