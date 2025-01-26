/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchellen <dchellen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:58:29 by dchellen          #+#    #+#             */
/*   Updated: 2025/01/26 13:21:51 by dchellen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	key_press_linux(int keycode, t_game *game)
// {
// 	if (keycode == 65307)
// 		mlx_free(game);
// 	if (keycode == 119 && move_up(game, 0, -1) == 1)
// 		mlx_free(game);
// 	if (keycode == 97 && move_left(game, -1, 0) == 1)
// 		mlx_free(game);
// 	if (keycode == 115 && move_down(game, 0, 1) == 1)
// 		mlx_free(game);
// 	if (keycode == 100 && move_right(game, 1, 0) == 1)
// 		mlx_free(game);
// 	return (0);
// }

int	key_press_mac(int keycode, t_game *game)
{
	if (keycode == 53)
		mlx_free(game);
	if (keycode == 13 && move_up(game, 0, -1) == 1)
		mlx_free(game);
	if (keycode == 0 && move_left(game, -1, 0) == 1)
		mlx_free(game);
	if (keycode == 1 && move_down(game, 0, 1) == 1)
		mlx_free(game);
	if (keycode == 2 && move_right(game, 1, 0) == 1)
		mlx_free(game);
	return (0);
}

int	close_window(t_game *game)
{
	printf("Fenetre quittée...\n");
	mlx_destroy_image(game->mlx_ptr, game->player.player);
	mlx_destroy_image(game->mlx_ptr, game->img.back);
	mlx_destroy_image(game->mlx_ptr, game->img.wall);
	mlx_destroy_image(game->mlx_ptr, game->img.exit);
	mlx_destroy_image(game->mlx_ptr, game->img.item);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	// mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_map_data(game->map.data);
	exit(0);
	return (0);
}

void	mlx_free(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->player.player);
	mlx_destroy_image(game->mlx_ptr, game->img.back);
	mlx_destroy_image(game->mlx_ptr, game->img.wall);
	mlx_destroy_image(game->mlx_ptr, game->img.exit);
	mlx_destroy_image(game->mlx_ptr, game->img.item);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	// mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_map_data(game->map.data);
	exit(0);
	return ;
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
