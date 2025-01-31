/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:00:26 by david             #+#    #+#             */
/*   Updated: 2025/01/31 13:08:27 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_size(t_game *game)
{
	size_t	size;
	size_t	current_size;

	game->map.x = 0;
	game->map.y = 0;
	size = ft_strlen(game->map.data[game->map.x]);
	if (game->map.data[game->map.x][size - 1] == '\n')
		size--;
	game->map.x++;
	while (game->map.data[game->map.x] != NULL)
	{
		current_size = ft_strlen(game->map.data[game->map.x]);
		if (game->map.data[game->map.x][current_size - 1] == '\n')
			current_size--;
		if (current_size != size)
			return (1);
		game->map.x++;
	}
	game->en_c = count_items(game, 'X');
	return (0);
}

int	check_map_wall(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map.data[0][x] != '\0' && game->map.data[0][x] != '\n')
	{
		if (game->map.data[0][x] != '1')
			return (1);
		x++;
	}
	y = 1;
	while (y < game->map.height - 1)
	{
		if (game->map.data[y][0] != '1'
			|| game->map.data[y][game->map.width - 1] != '1')
			return (1);
		y++;
	}
	x = 0;
	while (game->map.data[game->map.height - 1][x] != '\0'
			&& game->map.data[game->map.height - 1][x] != '\n')
		if (game->map.data[game->map.height - 1][x++] != '1')
			return (1);
	return (0);
}

int	count_items(t_game *game, char c)
{
	int	count;

	count = 0;
	game->map.y = 0;
	while (game->map.y < game->map.height)
	{
		game->map.x = 0;
		while (game->map.x < game->map.width)
		{
			if (game->map.data[game->map.y][game->map.x] == c)
				count++;
			game->map.x++;
		}
		game->map.y++;
	}
	return (count);
}

int	check_letters(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.data[y] != NULL)
	{
		x = 0;
		while (game->map.data[y][x] != '\0' && game->map.data[y][x] != '\n')
		{
			if (game->map.data[y][x] != '1'
				&& game->map.data[y][x] != '0'
				&& game->map.data[y][x] != 'P'
				&& game->map.data[y][x] != 'C'
				&& game->map.data[y][x] != 'E'
				&& game->map.data[y][x] != 'X')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	find_player_position(t_game *game)
{
	game->map.y = 0;
	while (game->map.y < game->map.height)
	{
		game->map.x = 0;
		while (game->map.x < game->map.width)
		{
			if (game->map.data[game->map.y][game->map.x] == 'P')
			{
				game->player.px = game->map.x;
				game->player.py = game->map.y;
				return ;
			}
			game->map.x++;
		}
		game->map.y++;
	}
	return ;
}
