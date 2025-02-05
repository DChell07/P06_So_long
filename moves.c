/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:58:29 by dchellen          #+#    #+#             */
/*   Updated: 2025/02/04 14:02:39 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press_linux(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		ft_printf("Window closed...\n");
		mlx_free(game);
	}
	if (keycode == 119 && move_up(game, 0, -1) == 1)
		mlx_free(game);
	if (keycode == 97 && move_left(game, -1, 0) == 1)
		mlx_free(game);
	if (keycode == 115 && move_down(game, 0, 1) == 1)
		mlx_free(game);
	if (keycode == 100 && move_right(game, 1, 0) == 1)
		mlx_free(game);
	return (0);
}

int	move_up(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.px + dx;
	new_y = game->player.py + dy;
	if (conditions(game, new_x, new_y) == 1)
		return (0);
	print_moves(game);
	if (print_win(game, new_x, new_y) == 1)
		return (1);
	else if (game->map.data[new_y][new_x] == 'E')
		return (0);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->img.back, game->player.px * IMG, game->player.py * IMG);
	game->map.data[game->player.py][game->player.px] = '0';
	game->player.px = new_x;
	game->player.py = new_y;
	game->map.data[game->player.py][game->player.px] = 'P';
	if (kill_collision(game) == 1)
		exit (0);
	dash_up(game, new_x, new_y);
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
	if (conditions(game, new_x, new_y) == 1)
		return (0);
	print_moves(game);
	if (print_win(game, new_x, new_y) == 1)
		return (1);
	else if (game->map.data[new_y][new_x] == 'E')
		return (0);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->img.back, game->player.px * IMG, game->player.py * IMG);
	game->map.data[game->player.py][game->player.px] = '0';
	game->player.px = new_x;
	game->player.py = new_y;
	game->map.data[game->player.py][game->player.px] = 'P';
	if (kill_collision(game) == 1)
		exit (0);
	dash_left(game, new_x, new_y);
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
	if (conditions(game, new_x, new_y) == 1)
		return (0);
	print_moves(game);
	if (print_win(game, new_x, new_y) == 1)
		return (1);
	else if (game->map.data[new_y][new_x] == 'E')
		return (0);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->img.back, game->player.px * IMG, game->player.py * IMG);
	game->map.data[game->player.py][game->player.px] = '0';
	game->player.px = new_x;
	game->player.py = new_y;
	game->map.data[game->player.py][game->player.px] = 'P';
	if (kill_collision(game) == 1)
		exit (0);
	dash_down(game, new_x, new_y);
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
	if (conditions(game, new_x, new_y) == 1)
		return (0);
	print_moves(game);
	if (print_win(game, new_x, new_y) == 1)
		return (1);
	else if (game->map.data[new_y][new_x] == 'E')
		return (0);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->img.back, game->player.px * IMG, game->player.py * IMG);
	game->map.data[game->player.py][game->player.px] = '0';
	game->player.px = new_x;
	game->player.py = new_y;
	game->map.data[game->player.py][game->player.px] = 'P';
	if (kill_collision(game) == 1)
		exit (0);
	dash_right(game, new_x, new_y);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->player.player, new_x * IMG, new_y * IMG);
	return (0);
}
