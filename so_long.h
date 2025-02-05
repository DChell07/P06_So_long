/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:02:19 by dchellen          #+#    #+#             */
/*   Updated: 2025/02/05 21:54:01 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "X11/keysym.h"
# include "ftt_printf/ft_printf.h"
# include <X11/X.h>
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

# define IMG 128
# define KILL -1

typedef struct s_enemy
{
	void		*img;
	void		*img_2;
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
	bool		alive;
}	t_enemy;

typedef struct s_img
{
	void		*back;
	void		*wall;
	void		*exit;
	void		*item_1;
	void		*item_2;
	void		*item_3;
	void		*item_4;
	void		*item_5;
	void		*item_6;
	void		*item_7;
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
	void		*player_l;
	void		*player_r;
	void		*player_u;
	void		*player_d;
	int			px;
	int			py;
}	t_player;

typedef struct s_count
{
	void	*c_1;
	void	*c_2;
	void	*c_3;
	void	*c_4;
	void	*c_5;
	void	*c_6;
	void	*c_7;
	void	*c_8;
}	t_count;

typedef struct s_kame
{
	void	*kame_1;
	void	*kame_2;
	void	*kame_3;
}	t_kame;


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
	t_count		count;
	t_kame		kame;
	int			active;
	t_enemy		*enemy;
	int			en_c;
	int			en_index;
}	t_game;

int		error_arg(int arg);
int		check_file(char *s1);

int		read_map_file(char *av, t_game *game);
int		check_fd(int fd);
void	give_map_data(char **map, t_game *game);
int		count_line(char *av);

int		check_error(t_game *game);
int		check_map_size(t_game *game);
int		check_map_wall(t_game *game);
int		count_items(t_game *game, char c);
int		check_letters(t_game *game);
int		check_map_accessibility(t_game *game);
void	find_player_position(t_game *game);
void	flood_fill(t_game *game, char **map_copy, int x, int y);

void	begin_message(void);

int		init_img(t_game *game);
int		init_items(t_game *game);
int		creat_map(t_game *game);
void	maploop(t_game *game);
void	maploop_cond(t_game *game);
void	add_count(t_game *game);
int		back_ground_img(t_game *game);
int		dragon_ball_img(t_game *game);

int		key_press_linux(int keycode, t_game *game);
int		close_window(t_game *game);
int		move_up(t_game *game, int px, int py);
int		move_left(t_game *game, int dx, int dy);
int		move_down(t_game *game, int dx, int dy);
int		move_right(t_game *game, int dx, int dy);

int		kame(t_game *game);

void	dash_left(t_game *game, int new_x, int new_y);
void	dash_right(t_game *game, int new_x, int new_y);
void	dash_up(t_game *game, int new_x, int new_y);
void	dash_down(t_game *game, int new_x, int new_y);
int		conditions(t_game *game, int new_x, int new_y);
void	print_moves(t_game *game);
int		print_win(t_game *game, int new_x, int new_y);

void	mlx_free(t_game *game);
void	free_map_data(char **map_data);
void	custom_usleep(int delay);

int		init_enemies(t_game *game);
int		put_enemies(t_game *game);
int		creat_enemies(t_game *game);
int		animate_enemy_1(t_game *game, int i);
int		animate_enemy_2(t_game *game, int i);
int		enemies_conditions_1(t_game *game, int i);
int		enemies_conditions_2(t_game *game, int i);
int		kill_collision(t_game *game);
int		kill_ennemis(t_game *game, int new_x, int new_y);
void	free_enemies(t_game *game);

#endif
