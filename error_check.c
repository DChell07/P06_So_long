/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:18:36 by dchellen          #+#    #+#             */
/*   Updated: 2025/01/24 20:01:10 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_error(t_game *game)
{
	if (check_map_accessibility(game) == 1)
	{
		printf("Inaccessibilité dans la map\n");
		return (1);
	}
	if (count_items(game, 'I') < 1 || count_items(game, 'E') != 1
		|| count_items(game, 'P') != 1)
	{
		printf("le nombres d'items est incorrect\n");
		return (1);
	}
	if (check_map_size(game) == 1)
	{
		printf("La taille de la map n'est pas correct\n");
		return (1);
	}
	printf("Map Valide\n");
	return (0);
}

void	dfs(t_game *game, char **map_copy, int x, int y)
{
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	if (map_copy[y][x] == 'I')
		game->items_take++;
	else if (game->items_take != game->map.items_nb && map_copy[y][x] == 'E')
		return ;
	else if (map_copy[y][x] == 'E')
		game->exit = true;
	map_copy[y][x] = 'V';
	dfs(game, map_copy, x + 1, y);
	dfs(game, map_copy, x - 1, y);
	dfs(game, map_copy, x, y + 1);
	dfs(game, map_copy, x, y - 1);
}

int	check_map_accessibility(t_game *game)
{
	int		i;
	int		start_x;
	int		start_y;
	char	**map_copy;

	i = 0;
	game->map.items_nb = 0;
	map_copy = malloc((game->map.height + 1) * sizeof(char *));
	if (map_copy == NULL)
		return (0);
	while (i < game->map.height)
	{
		map_copy[i] = ft_strdup(game->map.data[i]);
		i++;
	}
	map_copy[i] = NULL;
	find_player_position(game);
	game->map.items_nb = count_items(game, 'I');
	start_x = game->player.px;
	start_y = game->player.py;
	game->exit = false;
	dfs(game, map_copy, start_x, start_y);
	free_map_data(map_copy);
	if (game->items_take != game->map.items_nb)
		return (1);
	if (game->exit == false)
		return (1);
	return (0);
}

int	check_file(char *s1)
{
	size_t	size_s1;

	size_s1 = ft_strlen(s1);
	if (size_s1 < 4)
	{
		printf("invalide file sorry\n");
		return (1);
	}
	if (ft_strncmp(s1 + size_s1 - 4, ".ber", 4) != 0)
	{
		printf("invalide file\n");
		return (1);
	}
	return (0);
}

int	check_map_size(t_game *game)
{
	size_t	size;

	game->map.x = 0;
	game->map.y = 0;
	size = ft_strlen(game->map.data[game->map.x]);
	game->map.x++;
	while (game->map.data[game->map.x] != NULL)
	{
		if (ft_strlen(game->map.data[game->map.x]) != size)
			return (1);
		game->map.x++;
	}
	game->map.width *= IMG;
	game->map.height *= IMG;
	game->map.items_nb = 0;
	game->items_take = 0;
	return (0);
}
