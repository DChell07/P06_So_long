/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:23:38 by david             #+#    #+#             */
/*   Updated: 2025/01/28 20:12:44 by david            ###   ########.fr       */
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

int	kill_collision(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->en_c)
	{
		if (game->player.px == game->enemy[i].x
			&& game->player.py == game->enemy[i].y)
		{
			printf("Vous avez été tué !");
			mlx_free(game);
			return (1);
		}
		i++;
	}
	return (0);
}
