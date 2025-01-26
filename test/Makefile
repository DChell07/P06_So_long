# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchellen <dchellen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 12:58:56 by dchellen          #+#    #+#              #
#    Updated: 2025/01/26 13:33:08 by dchellen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile du Mac

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLX_PATH = mlx_mac/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -framework OpenGL -framework AppKit

CFILES = main.c

OBJECTS = $(CFILES:.c=.o)

all: subsystems $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<

subsystems:
	@make -C $(MLX_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) -o $(NAME)

clean:
	make -C $(MLX_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(MLX_PATH) fclean
	rm -f $(NAME)

re: fclean all
