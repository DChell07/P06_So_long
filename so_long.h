/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:02:19 by dchellen          #+#    #+#             */
/*   Updated: 2025/01/29 11:33:00 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// #include "mlx_mac/mlx.h"
# include "mlx_linux/mlx.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

# define BUFFER_SIZE 1024
# define IMG 64
# define KILL -1

typedef struct s_enemy
{
	void		*img;
	int			x;
	int			y;
	int			min_x;
	int			max_x;
	int			min_y;
	int			max_y;
	int			speed_x;
	int			speed_y;
	int			new_enemy_x;
	int			new_enemy_y;
}	t_enemy;

typedef struct s_img
{
	void		*back;
	void		*wall;
	void		*exit;
	void		*item;
}	t_img;

typedef struct s_map
{
	char		**data;
	int			height;
	int			width;
	int			x;
	int			y;
	int			items_nb;
}	t_map;

typedef struct s_player
{
	void		*player;
	int			px;
	int			py;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			items_take;
	int			moves_nb;
	bool		exit;
	t_img		img;
	t_map		map;
	t_player	player;
	t_enemy		*enemy;
	int			en_c;
	int			en_index;
}	t_game;


int		error_arg(int arg);
int		read_map_file(char *av, t_game *game);

int		check_file(char *s1);
int		check_map_size(t_game *game);
int		check_error(t_game *game);
int		count_items(t_game *game, char c);
int		check_map_accessibility(t_game *game);
int		check_map_wall(t_game *game);
int		check_letters(t_game *game);

void	find_player_position(t_game *game);
int		count_items(t_game *game, char c);
void	flood_fill(t_game *game, char **map_copy, int x, int y);
int		init_img(t_game *game);
int		creat_map(t_game *game);
void	maploop(t_game *game);
void	maploop_cond(t_game *game);

// int		key_press_mac(int keycode, t_game *game);
int		key_press_linux(int keycode, t_game *game);
int		close_window(t_game *game);
int		move_up(t_game *game, int px, int py);
int		move_left(t_game *game, int dx, int dy);
int		move_down(t_game *game, int dx, int dy);
int		move_right(t_game *game, int dx, int dy);

void	print_moves(t_game *game);
int		print_win(t_game *game, int new_x, int new_y);
int		conditions(t_game *game, int new_x, int new_y);
void	free_map_data(char **map_data);
void	mlx_free(t_game *game);

int		put_enemies(t_game *game);
int		init_enemies(t_game *game);
int		animate_enemy_1(t_game *game, int i);
int		animate_enemy_2(t_game *game, int i);
int		enemies_conditions_1(t_game *game, int i);
int		enemies_conditions_2(t_game *game, int i);
int		kill_collision(t_game *game);
int		creat_enemies(t_game *game);
void	free_enemies(t_game *game);

#endif
