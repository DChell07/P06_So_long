/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_cond.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:41:23 by dchellen          #+#    #+#             */
/*   Updated: 2025/02/05 17:28:53 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	conditions(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map.width
		|| new_y < 0 || new_y >= game->map.height)
		return (1);
	else if (game->map.data[new_y][new_x] == '1')
		return (1);
	else if (game->map.data[new_y][new_x] == 'C')
	{
		game->items_take++;
		game->map.data[new_y][new_x] = '0';
		add_count(game);
	}
	return (0);
}

void	print_moves(t_game *game)
{
	game->moves_nb++;
	ft_printf("moves numbers %d\n", game->moves_nb);
	return ;
}

int	print_win(t_game *game, int new_x, int new_y)
{
	if (game->map.data[new_y][new_x] == 'E'
			&& game->items_take == game->map.items_nb)
	{
        ft_printf("\n");
        ft_printf("__      __ _____  _____  _______  ____   _____ __     __ _ \n");
        ft_printf("\\ \\    / /|_   _|/ ____||__   __|/ __ \\ |  __  \\ \\   / /| |\n");
        ft_printf(" \\ \\  / /   | | | |        | |  | |  | || |__) |\\ \\_/ / | |\n");
        ft_printf("  \\ \\/ /    | | | |        | |  | |  | ||  _  /  \\   /  | |\n");
        ft_printf("   \\  /    _| |_| |____    | |  | |__| || | \\ \\   | |   |_|\n");
        ft_printf("    \\/    |_____|\\_____|   |_|   \\____/ |_|  \\_\\  |_|   (_)\n");
        ft_printf("\nTry the next lvl..?\n");
	    ft_printf("\n");
		return (1);
	}
	return (0);
}
