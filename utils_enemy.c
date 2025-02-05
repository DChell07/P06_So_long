/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:48:12 by david             #+#    #+#             */
/*   Updated: 2025/02/03 22:20:34 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_enemies(t_game *game)
{
	int	widht;
	int	height;
	int	i;

	widht = IMG;
	height = IMG;
	i = 0;
	game->enemy = malloc(sizeof(t_enemy) * game->en_c);
	while (i < game->en_c)
	{
		game->enemy[i].img = mlx_xpm_file_to_image(game->mlx_ptr,
				"asset/enemy.xpm", &widht, &height);
		game->enemy[i].img_2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/enemy_2.xpm", &widht, &height);
		i++;
	}
	return (0);
}

int	put_enemies(t_game *game)
{
	int	i;

	i = game->en_index;
	game->enemy[i].x = game->map.x;
	game->enemy[i].y = game->map.y;
	game->enemy[i].speed_y = 1;
	game->enemy[i].speed_x = 1;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->enemy[i].img, game->enemy[i].x * IMG, game->enemy[i].y * IMG);
	return (0);
}

int	kill_collision(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->en_c)
	{
		if (game->player.px == game->enemy[i].x
			&& game->player.py == game->enemy[i].y)
		{
			ft_printf("You've been killed !");
			mlx_free(game);
			return (1);
		}
		i++;
	}
	return (0);
}

void	free_enemies(t_game *game)
{
	int	i;

	if (game->enemy != 0)
	{
		i = 0;
		while (i < game->en_c)
		{
			mlx_destroy_image(game->mlx_ptr, game->enemy[i].img);
			mlx_destroy_image(game->mlx_ptr, game->enemy[i].img_2);
			i++;
		}
		free(game->enemy);
		game->enemy = NULL;
	}
}
