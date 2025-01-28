/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:00:26 by david             #+#    #+#             */
/*   Updated: 2025/01/29 00:46:33 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_wall(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map.data[0][x] != '\0')
		if (game->map.data[0][x++] != '1')
			return (1);
	y = 1;
	while (y < game->map.height - 1)
	{
		if (game->map.data[y][0] != '1' ||
			game->map.data[y][game->map.width - 1] != '1')
			return (1);
		y++;
	}
	x = 0;
	y = game->map.height - 1;
	while (game->map.data[y][x] != '\0')
	{
		if (game->map.data[y][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

int	check_letters(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.data[y] != NULL)
	{
		x = 0;
		while (game->map.data[y][x] != '\0')
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

int	error_arg(int arg)
{
	if (arg != 2)
	{
		printf("Error ARG, please write a map\n");
		return (1);
	}
	return (0);
}

void	print_moves(t_game *game)
{
	game->moves_nb++;
	printf("moves numbers %d\n", game->moves_nb);
	return ;
}
