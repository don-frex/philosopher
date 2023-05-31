# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaber <asaber@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 21:48:43 by asaber            #+#    #+#              #
#    Updated: 2023/05/31 21:50:37 by asaber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = CC

CFLAGS = -Wall -Wextra -Werror

SRC = philo.c libft/ft_lstnew.c libft/ft_lstadd_back.c libft/ft_isdigit.c ./libft/linked_circle.c init.c libft/ft_atoi.c threads.c

OBJS = $(philo:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean