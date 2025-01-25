/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:41:23 by dchellen          #+#    #+#             */
/*   Updated: 2025/01/24 19:16:07 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.px + dx;
	new_y = game->player.py + dy;
	if (new_x < 0 || new_x >= game->map.width || new_y < 0 || new_y >= game->map.height)
		return (0);
	else if (game->map.data[new_y][new_x] == '1')
		return (0);
	else if (game->map.data[new_y][new_x] == 'I')
	{
		game->items_take++;
		game->map.data[new_y][new_x] = '0';
	}
	else if (game->map.data[new_y][new_x] == 'E' && game->items_take == game->map.items_nb
			&& print_win() == 1)
		return (1);
	else if (game->map.data[new_y][new_x] == 'E')
		return (0);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img.back, game->player.px * IMG, game->player.py * IMG);
	game->player.px = new_x;
	game->player.py = new_y;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->player.player, new_x * IMG, new_y * IMG);
	return (0);
}

int	move_left(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.px + dx;
	new_y = game->player.py + dy;
	if (new_x < 0 || new_x >= game->map.width || new_y < 0 || new_y >= game->map.height)
		return (0);
	if (game->map.data[new_y][new_x] == '1')
		return (0);
	else if (game->map.data[new_y][new_x] == 'I')
	{
		game->items_take++;
		game->map.data[new_y][new_x] = '0';
	}
	else if (game->map.data[new_y][new_x] == 'E' && game->items_take == game->map.items_nb
			&& print_win() == 1)
		return (1);
	else if (game->map.data[new_y][new_x] == 'E')
		return (0);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img.back, game->player.px * IMG, game->player.py * IMG);
	game->player.px = new_x;
	game->player.py = new_y;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->player.player, new_x * IMG, new_y * IMG);
	return (0);
}

int	move_down(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.px + dx;
	new_y = game->player.py + dy;
	if (new_x < 0 || new_x >= game->map.width || new_y < 0 || new_y >= game->map.height)
		return (0);
	if (game->map.data[new_y][new_x] == '1')
		return (0);
	else if (game->map.data[new_y][new_x] == 'I')
	{
		game->items_take++;
		game->map.data[new_y][new_x] = '0';
	}
	else if (game->map.data[new_y][new_x] == 'E' && game->items_take == game->map.items_nb
			&& print_win() == 1)
		return (1);
	else if (game->map.data[new_y][new_x] == 'E')
		return (0);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img.back, game->player.px * IMG, game->player.py * IMG);
	game->player.px = new_x;
	game->player.py = new_y;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->player.player, new_x * IMG, new_y * IMG);
	return (0);
}

int	move_right(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.px + dx;
	new_y = game->player.py + dy;
	if (new_x < 0 || new_x >= game->map.width || new_y < 0 || new_y >= game->map.height)
		return (0);
	if (game->map.data[new_y][new_x] == '1')
		return (0);
	else if (game->map.data[new_y][new_x] == 'I')
	{
		game->items_take++;
		game->map.data[new_y][new_x] = '0';
	}
	else if (game->map.data[new_y][new_x] == 'E' && game->items_take == game->map.items_nb
			&& print_win() == 1)
		return (1);
	else if (game->map.data[new_y][new_x] == 'E')
		return (0);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img.back, game->player.px * IMG, game->player.py * IMG);
	game->player.px = new_x;
	game->player.py = new_y;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->player.player, new_x * IMG, new_y * IMG);
	return (0);
}

int	print_win(void)
{
	printf("YOU WIN!\n");
	return (1);
}
