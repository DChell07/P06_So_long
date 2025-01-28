# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david <david@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 11:27:47 by david             #+#    #+#              #
#    Updated: 2025/01/29 00:38:40 by david            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile du Linux

NAME = so_long

CC = cc

SRCS        =   enemy.c \
				error_check_2.c \
				error_check.c \
				events.c \
				main.c \
				map.c \
				moves.c \
				utils.c \
				utils_enemy.c

CFLAGS = -Wall -Wextra -Werror -g

MLX_PATH = mlx_linux/

MLX_LIB = $(MLX_PATH)libmlx_Linux.a

MLX_FLAGS = -Lmlx -L/usr/lib/X11 -lXext -lX11

LIBFT_PATH = ft_printf/

LIBFT_LIB = $(LIBFT_PATH)libftprintf.a


OBJECTS = $(SRCS:%.c=%.o)

all: subsystems $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<

subsystems:
	@make -C $(MLX_PATH) all
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX_LIB) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

clean:
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all
