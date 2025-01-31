/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:14:16 by dchellen          #+#    #+#             */
/*   Updated: 2025/01/31 12:21:57 by david            ###   ########.fr       */
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
	game->player.player = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/player.xpm", &widht, &height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/exit.xpm", &widht, &height);
	game->img.item = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/item.xpm", &widht, &height);
	init_enemies(game);
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
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img.item, game->map.x * IMG, game->map.y * IMG);
		game->map.items_nb++;
	}
	return ;
}
