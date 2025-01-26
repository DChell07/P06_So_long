/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchellen <dchellen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:14:16 by dchellen          #+#    #+#             */
/*   Updated: 2025/01/26 19:04:45 by dchellen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_game *game)
{
	game->moves_nb++;
	printf("moves numbers %d\n", game->moves_nb);
	return ;
}

int	print_win(t_game *game, int new_x, int new_y)
{
	if (game->map.data[new_y][new_x] == 'E'
			&& game->items_take == game->map.items_nb)
	{
		printf("YOU WIN!\n");
		return (1);
	}
	return (0);
}

int	conditions(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map.width
		|| new_y < 0 || new_y >= game->map.height)
		return (1);
	else if (game->map.data[new_y][new_x] == '1')
		return (1);
	else if (game->map.data[new_y][new_x] == 'I')
	{
		game->items_take++;
		game->map.data[new_y][new_x] = '0';
	}
	return (0);
}

void	maploop(t_game *game)
{
	while (game->map.x < game->map.width / IMG)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img.back, game->map.x * IMG, game->map.y * IMG);
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
		else if (game->map.data[game->map.y][game->map.x] == 'I')
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img.item, game->map.x * IMG, game->map.y * IMG);
			game->map.items_nb++;
		}
		game->map.x++;
	}
	return ;
}
