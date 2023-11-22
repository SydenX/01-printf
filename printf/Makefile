# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 11:43:18 by jtollena          #+#    #+#              #
#    Updated: 2023/11/22 13:04:09 by jtollena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c \
		srcs/helper.c \
		srcs/putter.c

NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)
INCLUDES = includes/ft_printf.h
FLAGS = -Wall -Wextra -Werror

.c.o:
	gcc $(FLAGS) -I includes -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(INCLUDES)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

bonus: all

re: clean fclean all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

.PHONY:
	all clean fclean re bonus