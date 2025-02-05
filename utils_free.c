/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:14:16 by dchellen          #+#    #+#             */
/*   Updated: 2025/02/04 14:02:37 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_free(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->player.player);
	mlx_destroy_image(game->mlx_ptr, game->player.player_l);
	mlx_destroy_image(game->mlx_ptr, game->player.player_r);
	mlx_destroy_image(game->mlx_ptr, game->player.player_u);
	mlx_destroy_image(game->mlx_ptr, game->player.player_d);
	mlx_destroy_image(game->mlx_ptr, game->img.back);
	mlx_destroy_image(game->mlx_ptr, game->img.wall);
	mlx_destroy_image(game->mlx_ptr, game->img.exit);
	mlx_destroy_image(game->mlx_ptr, game->img.item_1);
	mlx_destroy_image(game->mlx_ptr, game->img.item_2);
	mlx_destroy_image(game->mlx_ptr, game->img.item_3);
	mlx_destroy_image(game->mlx_ptr, game->img.item_4);
	mlx_destroy_image(game->mlx_ptr, game->img.item_5);
	mlx_destroy_image(game->mlx_ptr, game->img.item_6);
	mlx_destroy_image(game->mlx_ptr, game->img.item_7);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	free_enemies(game);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_map_data(game->map.data);
	exit(0);
	return ;
}

int	close_window(t_game *game)
{
	ft_printf("Window closed...\n");
	mlx_destroy_image(game->mlx_ptr, game->player.player);
	mlx_destroy_image(game->mlx_ptr, game->player.player_l);
	mlx_destroy_image(game->mlx_ptr, game->player.player_r);
	mlx_destroy_image(game->mlx_ptr, game->player.player_u);
	mlx_destroy_image(game->mlx_ptr, game->player.player_d);
	mlx_destroy_image(game->mlx_ptr, game->img.back);
	mlx_destroy_image(game->mlx_ptr, game->img.wall);
	mlx_destroy_image(game->mlx_ptr, game->img.exit);
	mlx_destroy_image(game->mlx_ptr, game->img.item_1);
	mlx_destroy_image(game->mlx_ptr, game->img.item_2);
	mlx_destroy_image(game->mlx_ptr, game->img.item_3);
	mlx_destroy_image(game->mlx_ptr, game->img.item_4);
	mlx_destroy_image(game->mlx_ptr, game->img.item_5);
	mlx_destroy_image(game->mlx_ptr, game->img.item_6);
	mlx_destroy_image(game->mlx_ptr, game->img.item_7);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	free_enemies(game);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_map_data(game->map.data);
	exit(0);
	return (0);
}

void	free_map_data(char **map_data)
{
	int	i;

	if (map_data == NULL)
		return ;
	i = 0;
	while (map_data[i] != NULL)
	{
		free(map_data[i]);
		i++;
	}
	free(map_data);
	map_data = NULL;
}
