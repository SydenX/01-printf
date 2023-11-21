# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 11:43:18 by jtollena          #+#    #+#              #
#    Updated: 2023/11/21 16:15:55 by jtollena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c \
		srcs/helper.c \

# BONUS_SRCS = 

NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)
# BONUS_OBJS = $(BONUS_SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

.c.o:
	gcc $(FLAGS) -I./ -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

# bonus: $(OBJS) $(BONUS_OBJS) $(INCLUDES)
# 	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

re: clean fclean all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

.PHONY:
	all clean fclean re bonus