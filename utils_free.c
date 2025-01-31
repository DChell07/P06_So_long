/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:14:16 by dchellen          #+#    #+#             */
/*   Updated: 2025/01/31 12:30:11 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_free(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->player.player);
	mlx_destroy_image(game->mlx_ptr, game->img.back);
	mlx_destroy_image(game->mlx_ptr, game->img.wall);
	mlx_destroy_image(game->mlx_ptr, game->img.exit);
	mlx_destroy_image(game->mlx_ptr, game->img.item);
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
	ft_printf("Fenetre quittée...\n");
	mlx_destroy_image(game->mlx_ptr, game->player.player);
	mlx_destroy_image(game->mlx_ptr, game->img.back);
	mlx_destroy_image(game->mlx_ptr, game->img.wall);
	mlx_destroy_image(game->mlx_ptr, game->img.exit);
	mlx_destroy_image(game->mlx_ptr, game->img.item);
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

void	print_map(char **map)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		ft_printf("%s", map[y]);
		y++;
	}
	ft_printf("\n");
	return ;
}
