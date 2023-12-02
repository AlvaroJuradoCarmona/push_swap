# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 14:10:58 by ajurado-          #+#    #+#              #
#    Updated: 2023/12/02 14:10:58 by ajurado-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I $(LIBFT)
LIBFT		= libft
LIBFT_A		= $(LIBFT)/libft.a
SRCS		= push_swap.c initial_check.c
OBJS		= $(SRCS:.c=.o)
RM			= rm -rf

all: libft $(NAME)

libft:
	make -C $(LIBFT)

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(SRCS) $(LIBFT_A) $(INCLUDES) -o $(NAME)

clean: 
	make clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(LIBFT_A)
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re libft