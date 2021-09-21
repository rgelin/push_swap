# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 23:35:17 by rgelin            #+#    #+#              #
#    Updated: 2021/09/21 17:17:39 by rgelin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	./src/main.c \
		./src/list.c \
		./src/error.c \
		./src/functions.c \
		./src/functions_2.c \
		./src/sort_small_stack.c \
		./src/chunck.c \
		./src/sort_big_stack.c \
		./utils/ft_atoi.c \
		./utils/ft_is_digit.c \
		./utils/ft_split.c \
		./utils/ft_sort_int_tab.c

OBJS        =       $(SRCS:%.c=%.o)

CC          =       gcc

CFLAGS      =       -Wall -Wextra -Werror

REMOVE		=		rm -f

NAME		=		push_swap

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			@$(REMOVE) $(OBJS)

fclean:		clean
			@$(REMOVE) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re