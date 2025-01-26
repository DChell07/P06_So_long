/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchellen <dchellen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:41:23 by dchellen          #+#    #+#             */
/*   Updated: 2025/01/26 19:04:25 by dchellen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.px + dx;
	new_y = game->player.py + dy;
	print_moves(game);
	if (conditions(game, new_x, new_y) == 1)
		return (0);
	if (print_win(game, new_x, new_y) == 1)
		return (1);
	else if (game->map.data[new_y][new_x] == 'E')
		return (0);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->img.back, game->player.px * IMG, game->player.py * IMG);
	game->player.px = new_x;
	game->player.py = new_y;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->player.player, new_x * IMG, new_y * IMG);
	return (0);
}

int	move_left(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.px + dx;
	new_y = game->player.py + dy;
	print_moves(game);
	if (conditions(game, new_x, new_y) == 1)
		return (0);
	if (print_win(game, new_x, new_y) == 1)
		return (1);
	else if (game->map.data[new_y][new_x] == 'E')
		return (0);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->img.back, game->player.px * IMG, game->player.py * IMG);
	game->player.px = new_x;
	game->player.py = new_y;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->player.player, new_x * IMG, new_y * IMG);
	return (0);
}

int	move_down(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.px + dx;
	new_y = game->player.py + dy;
	print_moves(game);
	if (conditions(game, new_x, new_y) == 1)
		return (0);
	if (print_win(game, new_x, new_y) == 1)
		return (1);
	else if (game->map.data[new_y][new_x] == 'E')
		return (0);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->img.back, game->player.px * IMG, game->player.py * IMG);
	game->player.px = new_x;
	game->player.py = new_y;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->player.player, new_x * IMG, new_y * IMG);
	return (0);
}

int	move_right(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.px + dx;
	new_y = game->player.py + dy;
	print_moves(game);
	if (conditions(game, new_x, new_y) == 1)
		return (0);
	if (print_win(game, new_x, new_y) == 1)
		return (1);
	else if (game->map.data[new_y][new_x] == 'E')
		return (0);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->img.back, game->player.px * IMG, game->player.py * IMG);
	game->player.px = new_x;
	game->player.py = new_y;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->player.player, new_x * IMG, new_y * IMG);
	return (0);
}
