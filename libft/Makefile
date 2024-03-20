# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebellini <ebellini@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 17:33:04 by ebellini          #+#    #+#              #
#    Updated: 2024/03/21 00:00:25 by ebellini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utilities.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_atoi.c

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -f

FLAGS = -Wall -Werror -Wextra

.c.o:
		$(CC) $(FLAGS) -g -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
