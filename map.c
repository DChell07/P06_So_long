/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:14:16 by dchellen          #+#    #+#             */
/*   Updated: 2025/02/08 19:45:53 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_img(t_game *game)
{
	int	widht;
	int	height;

	widht = IMG;
	height = IMG;
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->map.width,
			game->map.height, "Dokkan Battle");
	game->img.back = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/fond.xpm", &widht, &height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/mur.xpm", &widht, &height);
	game->count.c_1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/C_1.xpm", &widht, &height);
	game->count.c_2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/C_2.xpm", &widht, &height);
	game->count.c_3 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/C_3.xpm", &widht, &height);
	game->count.c_4 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/C_4.xpm", &widht, &height);
	game->count.c_5 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/C_5.xpm", &widht, &height);
	game->count.c_6 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/C_6.xpm", &widht, &height);
	game->count.c_7 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/C_7.xpm", &widht, &height);
	game->count.c_8 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/C_8.xpm", &widht, &height);
	game->player.player = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/player.xpm", &widht, &height);
	game->player.player_l = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/player_l.xpm", &widht, &height);
	game->player.player_r = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/player_r.xpm", &widht, &height);
	game->player.player_u = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/player_u.xpm", &widht, &height);
	game->player.player_d = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/player_d.xpm", &widht, &height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/exit.xpm", &widht, &height);
	game->kame.kame_1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/kame_1.xpm", &widht, &height);
	game->kame.kame_2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/kame_2.xpm", &widht, &height);
	game->kame.kame_3 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/kame_3.xpm", &widht, &height);
	game->map.items_nb = 0;
	init_items(game);
	init_enemies(game);
	return (0);
}

int	init_items(t_game *game)
{
	int	widht;
	int	height;

	widht = IMG;
	height = IMG;
	game->items_take = 0;
	game->img.item_1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/item_1.xpm", &widht, &height);
	game->img.item_2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/item_2.xpm", &widht, &height);
	game->img.item_3 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/item_3.xpm", &widht, &height);
	game->img.item_4 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/item_4.xpm", &widht, &height);
	game->img.item_5 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/item_5.xpm", &widht, &height);
	game->img.item_6 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/item_6.xpm", &widht, &height);
	game->img.item_7 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/item_7.xpm", &widht, &height);
	return (0);
}

int	creat_map(t_game *game)
{
	game->map.y = 0;
	while (game->map.y < game->map.height / IMG)
	{
		game->map.x = 0;
		maploop(game);
		game->map.y++;
	}
	add_count(game);
	return (0);
}

void	maploop(t_game *game)
{
	while (game->map.x < game->map.width / IMG)
	{
		maploop_cond(game);
		if (game->map.data[game->map.y][game->map.x] == 'X')
		{
			put_enemies(game);
			game->en_index++;
		}
		game->map.x++;
	}
	return ;
}

void	maploop_cond(t_game *game)
{
	if (game->map.data[game->map.y][game->map.x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img.wall, game->map.x * IMG, game->map.y * IMG);
	else if (game->map.data[game->map.y][game->map.x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img.back, game->map.x * IMG, game->map.y * IMG);
	else if (game->map.data[game->map.y][game->map.x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->player.player, game->map.x * IMG, game->map.y * IMG);
	else if (game->map.data[game->map.y][game->map.x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img.exit, game->map.x * IMG, game->map.y * IMG);
	else if (game->map.data[game->map.y][game->map.x] == 'C')
	{
		dragon_ball_img(game);
		game->map.items_nb++;
	}
	return ;
}

void	add_count(t_game *game)
{
	size_t	size;

	game->map.y = 0;
	game->map.x = 0;
	size = ft_strlen(game->map.data[game->map.x]);
	if (game->map.data[game->map.x][size - 1] == '\n')
		size--;
	if (game->map.data[game->map.y][size - 1] == '\n')
		size--;
	if (size >= 5)
	{
		if (game->items_take == 0)
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->count.c_1, game->map.y, game->map.x);
		else if (game->items_take == 1)
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->count.c_2, game->map.y, game->map.x);
		else if (game->items_take == 2)
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->count.c_3, game->map.y, game->map.x);
		else if (game->items_take == 3)
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->count.c_4, game->map.y, game->map.x);
		else if (game->items_take == 4)
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->count.c_5, game->map.y, game->map.x);
		else if (game->items_take == 5)
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->count.c_6, game->map.y, game->map.x);
		else if (game->items_take == 6)
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->count.c_7, game->map.y, game->map.x);
		else if (game->items_take == 7)
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->count.c_8, game->map.y, game->map.x);
	}
	return ;
}

int	dragon_ball_img(t_game *game)
{
	if (game->map.items_nb == 0 || game->map.items_nb > 6)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img.item_1, game->map.x * IMG, game->map.y * IMG);
	if (game->map.items_nb == 1)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img.item_2, game->map.x * IMG, game->map.y * IMG);
	if (game->map.items_nb == 2)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img.item_3, game->map.x * IMG, game->map.y * IMG);
	if (game->map.items_nb == 3)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img.item_4, game->map.x * IMG, game->map.y * IMG);
	if (game->map.items_nb == 4)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img.item_5, game->map.x * IMG, game->map.y * IMG);
	if (game->map.items_nb == 5)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img.item_6, game->map.x * IMG, game->map.y * IMG);
	if (game->map.items_nb == 6)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img.item_7, game->map.x * IMG, game->map.y * IMG);
	return (0);
}
