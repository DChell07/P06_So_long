/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kame.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:24:54 by david             #+#    #+#             */
/*   Updated: 2025/02/06 01:05:35 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int kame(t_game *game)
{
	int new_x;
	int new_y;
	int prev_x;
    char prev_tile;

	new_x = game->player.px - 1;
	new_y = game->player.py;
	prev_x = new_x;
    prev_tile = game->map.data[new_y][prev_x];
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->kame.kame_1, game->player.px * IMG, game->player.py * IMG);
	while (game->map.data[new_y][new_x] != '1' &&
	       game->map.data[new_y][new_x] != 'E' &&
	       game->map.data[new_y][new_x] != 'C')
	{
 		if (kill_ennemis(game, new_x, new_y))
            break;
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img.back, prev_x * IMG, game->player.py * IMG);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->kame.kame_2, new_x * IMG, new_y * IMG);
		mlx_do_sync(game->mlx_ptr);
		usleep(50000);
		prev_x = new_x;
		new_x--;
	}
    if (prev_tile != '1' && prev_tile != 'E' && prev_tile != 'C')
    {
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
            game->img.back, prev_x * IMG, game->player.py * IMG);
    }
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->player.player, game->player.px * IMG, game->player.py * IMG);
	return (0);
}

int kill_ennemis(t_game *game, int new_x, int new_y)
{
	int	i;

	i = 0;
	while (i < game->en_c)
	{
        if (game->enemy[i].y == new_y && game->enemy[i].x == new_x)
        {
            game->enemy[i].alive = false;
            game->enemy[i].img = game->img.back;
            game->enemy[i].img_2 = game->img.back;
            game->map.data[game->enemy[i].y][game->enemy[i].x] = '0';
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->kame.kame_3, game->enemy[i].x * IMG, game->enemy[i].y * IMG);
            printf("ONE KILL !\n");
			mlx_do_sync(game->mlx_ptr);
			usleep(200000);
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img.back, game->enemy[i].x * IMG, game->enemy[i].y * IMG);
			return (1);
        }
    	i++;
    }
    return (0);
}
