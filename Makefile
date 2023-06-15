# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaber <asaber@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 21:48:43 by asaber            #+#    #+#              #
#    Updated: 2023/06/15 23:04:55 by asaber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = CC

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread

SRC = philo.c libft/ft_lstnew.c libft/ft_lstadd_back.c libft/ft_isdigit.c ./libft/linked_circle.c init.c libft/ft_atoi.c threads.c

OBJS = $(SRC:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC)  $(CFLAGS) $^ -o $(NAME)

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: 
	$(RM) $(OBJS) $(OBJSB) $(NAME) $(BONUS)

re: fclean all

.PHONY:all bonus clean fclean re