/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:55:48 by david             #+#    #+#             */
/*   Updated: 2025/02/02 01:20:12 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map_file(char *av, t_game *game)
{
	int		fd;
	int		count;
	int		i;
	char	**map;

	i = 0;
	fd = open(av, O_RDONLY);
	if (check_fd(fd) == 1)
		return (1);
	count = count_line(av);
	map = (char **)malloc(sizeof(char *) * (count + 1));
	if (map == NULL)
		return (1);
	while (1)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	game->map.data = map;
	give_map_data(map, game);
	return (0);
}

int	check_fd(int fd)
{
	if (fd == -1)
	{
		ft_printf("Invalid file\n");
		return (1);
	}
	return (0);
}

int	count_line(char *av)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(av, O_RDONLY);
	line = NULL;
	count = 0;
	if (fd == -1)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

void	give_map_data(char **map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[0][x] != '\n')
		x++;
	while (map[y] != NULL)
		y++;
	game->map.width = x;
	game->map.height = y;
	return ;
}
