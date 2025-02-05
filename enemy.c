/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:23:38 by david             #+#    #+#             */
/*   Updated: 2025/02/03 22:36:57 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	creat_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->en_c)
	{
		if (i % 2 == 0)
			animate_enemy_1(game, i);
		else
			animate_enemy_2(game, i);
		i++;
	}
	return (0);
}

int	animate_enemy_1(t_game *game, int i)
{
	static int	frame_count_1 = 0;
	void *temp_img;

	game->enemy[i].max_y = 100;
	game->enemy[i].min_y = 0;
	if (frame_count_1 % 19997 == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img.back, game->enemy[i].x * IMG, game->enemy[i].y * IMG);
		game->enemy[i].new_enemy_y = game->enemy[i].y + game->enemy[i].speed_y;
		if (enemies_conditions_1(game, i) == 1)
		{
			game->enemy[i].speed_y *= -1;
			temp_img = game->enemy[i].img;
			game->enemy[i].img = game->enemy[i].img_2;
			game->enemy[i].img_2 = temp_img; 
		}
		else
		{
			game->map.data[game->enemy[i].y][game->enemy[i].x] = '0';
			game->enemy[i].y = game->enemy[i].new_enemy_y;
			game->map.data[game->enemy[i].y][game->enemy[i].x] = 'X';
			if (kill_collision(game) == 1)
				exit (0);
		}
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->enemy[i].img, game->enemy[i].x * IMG, game->enemy[i].y * IMG);
	}
	frame_count_1++;
	return (0);
}

int	animate_enemy_2(t_game *game, int i)
{
	static int	frame_count_2 = 0;
	void *temp_img;

	game->enemy[i].max_x = 100;
	game->enemy[i].min_x = 0;
	if (frame_count_2 % 19997 == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img.back, game->enemy[i].x * IMG, game->enemy[i].y * IMG);
		game->enemy[i].new_enemy_x = game->enemy[i].x + game->enemy[i].speed_x;
		if (enemies_conditions_2(game, i) == 1)
		{
			game->enemy[i].speed_x *= -1;
			temp_img = game->enemy[i].img;
			game->enemy[i].img = game->enemy[i].img_2;
			game->enemy[i].img_2 = temp_img; 
		}
		else
		{
			game->map.data[game->enemy[i].y][game->enemy[i].x] = '0';
			game->enemy[i].x = game->enemy[i].new_enemy_x;
			game->map.data[game->enemy[i].y][game->enemy[i].x] = 'X';
			if (kill_collision(game) == 1)
				exit (0);
		}
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->enemy[i].img, game->enemy[i].x * IMG, game->enemy[i].y * IMG);
	}
	frame_count_2++;
	return (0);
}

int	enemies_conditions_1(t_game *game, int i)
{
	if (game->enemy[i].new_enemy_y < game->enemy[i].min_y
		|| game->enemy[i].new_enemy_y >= game->enemy[i].max_y
		|| game->map.data[game->enemy[i].new_enemy_y][game->enemy[i].x] == '1'
		|| game->map.data[game->enemy[i].new_enemy_y][game->enemy[i].x] == 'C'
		|| game->map.data[game->enemy[i].new_enemy_y][game->enemy[i].x] == 'E')
		return (1);
	return (0);
}

int	enemies_conditions_2(t_game *game, int i)
{
	if (game->enemy[i].new_enemy_x < game->enemy[i].min_x
		|| game->enemy[i].new_enemy_x >= game->enemy[i].max_x
		|| game->map.data[game->enemy[i].y][game->enemy[i].new_enemy_x] == '1'
		|| game->map.data[game->enemy[i].y][game->enemy[i].new_enemy_x] == 'C'
		|| game->map.data[game->enemy[i].y][game->enemy[i].new_enemy_x] == 'E')
		return (1);
	return (0);
}
