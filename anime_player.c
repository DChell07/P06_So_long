/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:06:49 by david             #+#    #+#             */
/*   Updated: 2025/02/04 14:04:59 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dash_left(t_game *game, int new_x, int new_y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->player.player_l, new_x * IMG, new_y * IMG);
	mlx_do_sync(game->mlx_ptr);
	usleep(100000);
}

void	dash_right(t_game *game, int new_x, int new_y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->player.player_r, new_x * IMG, new_y * IMG);
	mlx_do_sync(game->mlx_ptr);
	usleep(100000);
}

void	dash_up(t_game *game, int new_x, int new_y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->player.player_u, new_x * IMG, new_y * IMG);
	mlx_do_sync(game->mlx_ptr);
	usleep(100000);
}

void	dash_down(t_game *game, int new_x, int new_y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->player.player_d, new_x * IMG, new_y * IMG);
	mlx_do_sync(game->mlx_ptr);
	usleep(100000);
}
