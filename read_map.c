/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:55:48 by david             #+#    #+#             */
/*   Updated: 2025/01/30 22:03:17 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

void	print_map(char **map)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		printf("%s", map[y]);
		y++;
	}
	printf("\n");
	return ;
}

void 	give_map_data(char **map, t_game *game)
{
	int	y;
	int x;

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
