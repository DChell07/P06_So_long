/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:14:16 by dchellen          #+#    #+#             */
/*   Updated: 2025/01/30 16:30:11 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_win(t_game *game, int new_x, int new_y)
{
	if (game->map.data[new_y][new_x] == 'E'
			&& game->items_take == game->map.items_nb)
	{
		ft_printf("YOU WIN!\n");
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
	else if (game->map.data[new_y][new_x] == 'C')
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
		i++;
	}
	return (0);
}
