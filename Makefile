# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 11:43:18 by jtollena          #+#    #+#              #
#    Updated: 2023/11/16 14:50:20 by jtollena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 

BONUS_SRCS = 

NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
INCLUDES = libft.h
FLAGS = -Wall -Wextra -Werror

.c.o:
	gcc $(FLAGS) -I includes -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(INCLUDES)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

bonus: $(OBJS) $(BONUS_OBJS) $(INCLUDES)
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

re: clean fclean all

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME)

.PHONY:
	all clean fclean re bonus