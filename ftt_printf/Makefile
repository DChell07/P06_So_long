# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david_chellen <david_chellen@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 16:30:45 by dchellen          #+#    #+#              #
#    Updated: 2024/10/10 16:12:35 by david_chell      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRCS =	ft_printf_utiles.c \
		ft_printf.c \
		ft_printf_lib.c

OBJS := $(SRCS:%.c=%.o)

LIBFT = libft

FLAGS = -Wall -Werror -Wextra

RM = rm -f

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	mv libft.a $(NAME)
	gcc $(FLAGS) -c $(SRCS) -I ./
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean :
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/libft.a

re: fclean all
