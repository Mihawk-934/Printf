# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miclaude <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/15 16:33:11 by miclaude          #+#    #+#              #
#    Updated: 2019/12/15 16:33:14 by miclaude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_printf.c\
		ft_parsing.c\
		ft_init_struct.c\
		ft_modif_id.c\
		ft_modif_id2.c\
		ft_modif_oux.c\
		ft_modif_oux2.c\
		ft_modif_sc.c\
		ft_conversion.c\
		ft_strupcase.c\
		ft_attr_oux.c\
		ft_attr_id.c\
		ft_remp.c\
		ft_remp0.c\
		ft_champs_and_precision.c\
		ft_neg.c\
		ft_min.c\
		ft_string.c\
		ft_percen.c\
		ft_zero.c\
		ft_point.c\
		ft_strchr.c\
		ft_isdigit.c\
		ft_strjoin.c\
		ft_strdel.c\
		ft_strncat.c\
		ft_strncpy.c\
		ft_putchar.c\
		ft_strchr.c\
		ft_itoa_base.c\
		ft_strnlen.c\
		ft_putstr.c\
		ft_atoi.c\
		ft_strlen.c\
		ft_putnbr.c\
		ft_modif_big_dou.c

CFLAGS = -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

INCLUDES = .

CC = gcc

all : $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
