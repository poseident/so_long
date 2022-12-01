/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:37:01 by bschweit          #+#    #+#             */
/*   Updated: 2022/07/28 02:41:16 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	wall_control(t_game *game)
{
	int	y;
	int	x;
	int	k_x;
	int	k_y;

	k_x = (game->size_x / 48) - 1;
	k_y = (game->size_y / 48) - 1;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if ((y == 0 || x == 0) && game->map[y][x] != '1')
				message(RED"Error ! not only wall(1) in left-top map !\n", game);
			else if ((y == k_y || x == k_x) && game->map[y][x] != '1')
				message(RED"Error ! not only wall(1) in right-down map !\n", game);
			x++;
		}
		y++;
	}
}

void	map_control(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
				game->exitcheck++;
			x++;
		}
		y++;
	}
	if (game->coincheck == 0)
		message(RED"Error ! no coin(C) in map !\n", game);
	if (game->playercheck != 1)
		message(RED"Error ! no player(P) in map !\n", game);
	if (game->exitcheck != 1)
		message(RED"Error ! more or less than one Exit(E) in map !\n", game);
}

void	game_control(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->coincheck++;
			if (game->map[y][x] == 'P')
			{	
				game->playercheck++;
				game->player.x = x * SIZE;
				game->player.y = y * SIZE;
			}
			x++;
		}
		y++;
	}
	map_control(game);
	wall_control(game);
}

int	move_check(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1')
		return (1);
	else if (game->map[y][x] == 'C')
	{
		game->player.coin++;
		game->map[y][x] = '0';
	}
	else if (game->map[y][x] == 'E')
	{
		if (game->player.coin != game->coincheck)
		{
			ft_printf(RED"Take all perle before give them to etoile de mer !\n");
			return (1);
		}
		message(GREEN"CONGRATS\n", game);
		return (0);
	}
	return (0);
}
