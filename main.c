/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:58:28 by dchellen          #+#    #+#             */
/*   Updated: 2025/01/24 20:02:21 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac < 2)
	{
		printf("Error ARG\n");
		return (0);
	}
	ft_memset(&game, 0, sizeof(t_game));
	if (check_file(av[1]) == 1)
		return (0);
	game.mlx_ptr = mlx_init();
	read_map_file(av[1], &game);
	if (check_error(&game) == 1)
	{
		free_map_data(game.map.data);
		mlx_destroy_display(game.mlx_ptr);
		free(game.mlx_ptr);
		return (0);
	}
	init_img(&game);
	creat_map(&game);
	mlx_key_hook(game.mlx_win, key_press, &game);
	mlx_hook(game.mlx_win, 17, 0, close_window, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
