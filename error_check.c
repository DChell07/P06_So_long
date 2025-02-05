/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:18:36 by dchellen          #+#    #+#             */
/*   Updated: 2025/02/05 22:20:30 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_arg(int arg)
{
	if (arg != 2)
	{
		ft_printf("Error ARG, please write a map\n");
		return (1);
	}
	return (0);
}

int	check_file(char *s1)
{
	size_t	size_s1;

	size_s1 = ft_strlen(s1);
	if (size_s1 < 4)
	{
		ft_printf("invalide file\n");
		return (1);
	}
	if (ft_strncmp(s1 + size_s1 - 4, ".ber", 4) != 0)
	{
		ft_printf("invalide file\n");
		return (1);
	}
	return (0);
}

int	check_error(t_game *game)
{
	if (check_map_size(game) == 1 || check_map_wall(game) == 1)
	{
		ft_printf("Incorrect size or no wall map..\n");
		return (1);
	}
	if (count_items(game, 'C') < 1 || count_items(game, 'E') != 1
		|| count_items(game, 'P') != 1 || count_items(game, '0') < 1
		|| check_letters(game) == 1)
	{
		ft_printf("Incorrect map letters..\n");
		return (1);
	}
	if (check_map_accessibility(game) == 1)
	{
		ft_printf("Inaccessibily in map..\n");
		return (1);
	}
	game->map.width *= IMG;
	game->map.height *= IMG;	
	begin_message();
	return (0);
}

int	check_map_accessibility(t_game *game)
{
	int		i;
	int		start_x;
	int		start_y;
	char	**map_copy;

	i = 0;
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
	game->map.items_nb = count_items(game, 'C');
	start_x = game->player.px;
	start_y = game->player.py;
	game->exit = false;
	flood_fill(game, map_copy, start_x, start_y);
	free_map_data(map_copy);
	if (game->items_take != game->map.items_nb || game->exit == false)
		return (1);
	return (0);
}

void	flood_fill(t_game *game, char **map_copy, int x, int y)
{
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	if (map_copy[y][x] == 'C')
		game->items_take++;
	else if (map_copy[y][x] == 'E')
	{
		game->exit = true;
		return ;
	}
	map_copy[y][x] = 'V';
	flood_fill(game, map_copy, x + 1, y);
	flood_fill(game, map_copy, x - 1, y);
	flood_fill(game, map_copy, x, y + 1);
	flood_fill(game, map_copy, x, y - 1);
}

void begin_message(void)
{
	ft_printf("\n");
	ft_printf("\033[38;5;214m");
    ft_printf("██████╗ ██████╗  █████╗  ██████╗  ██████╗ ███╗   ██╗    ██████╗  █████╗ ██╗     ██╗     \n");
    ft_printf("██╔══██╗██╔══██╗██╔══██╗██╔════╝ ██╔═══██╗████╗  ██║    ██╔══██╗██╔══██╗██║     ██║     \n");
    ft_printf("██║  ██║██████╔╝███████║██║  ███╗██║   ██║██╔██╗ ██║    ██████╔ ███████║██║     ██║     \n");
    ft_printf("██║  ██║██╔══██╗██╔══██║██║   ██║██║   ██║██║╚██╗██║    ██╔══██ ██╔══██║██║     ██║     \n");
    ft_printf("██████╔╝██║  ██║██║  ██║╚██████╔╝╚██████╔╝██║ ╚████║    ██████╗╝██║  ██║███████╗███████╗\n");
	ft_printf("\nYou need to take all of the dragon balls\n");
	ft_printf("and go back to the kame house !\n");
	ft_printf("move with\n- W\n- A\n- S\n- D\nAnd exit the game with ESC or the cross\n");
    ft_printf("\n");
	return ;
}
