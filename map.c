/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:14:16 by dchellen          #+#    #+#             */
/*   Updated: 2025/01/24 20:00:43 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map_file(char *av, t_game *game)
{
	int		fd;
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	int		i;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (1);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	close(fd);
	buf[bytes_read] = '\0';
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			game->map.height++;
		else if (game->map.height == 0)
			game->map.width++;
		i++;
	}
	game->map.data = ft_split(buf, '\n');
	return (0);
}

int	init_img(t_game *game)
{
	int	widht;
	int	height;

	widht = IMG;
	height = IMG;
	game->moves_nb = 0;
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->map.width,
			game->map.height, "EKIP");
	if (game->mlx_win == NULL)
		return (1);
	game->img.back = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/fond.xpm", &widht, &height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/mur.xpm", &widht, &height);
	game->player.player = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/player.xpm", &widht, &height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/exit.xpm", &widht, &height);
	game->img.item = mlx_xpm_file_to_image(game->mlx_ptr,
			"asset/item.xpm", &widht, &height);
	return (0);
}

int	creat_map(t_game *game)
{
	game->map.y = 0;
	while (game->map.y < game->map.height / IMG)
	{
		game->map.x = 0;
		maploop(game);
		game->map.y++;
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
