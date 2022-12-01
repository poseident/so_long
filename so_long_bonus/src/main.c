/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:28:23 by bschweit          #+#    #+#             */
/*   Updated: 2022/07/28 06:57:43 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_check(int key_code, t_game *game)
{
	if (key_code == ESC)
		destroy_window(game);
	if (key_code == UP)
		up(game);
	if (key_code == RIGHT)
		right(game);
	if (key_code == DOWN)
		down(game);
	if (key_code == LEFT)
		left(game);
	return (0);
}

void	control_to_zero(t_game *game)
{
	game->coincheck = 0;
	game->playercheck = 0;
	game->exitcheck = 0;
	game->player.mouvement = 0;
	game->player.coin = 0;
}

void	message(char *str, t_game *game)
{
	ft_printf("%s", str);
	map_destroy(game);
	exit(0);
}

int main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		message(RED"Eroor! less or more than 1 map\n", &game);
	if (ft_strnstr(argv[1], ".ber", (ft_strlen(argv[1]))) == NULL)
		message(RED"ERROR, map dont finish by '.ber'\n", &game);
	window_size(&game, argv);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.size_x, game.size_y, "so_long");
	create_map(&game, argv);
	put_ctl(&game);
	control_to_zero(&game);
	game_control(&game);
	ft_printf(BLUE"bring the pearl to the starfish !\n");
	mlx_hook(game.win, 17, 1L << 2, destroy_window, &game);
	mlx_key_hook(game.win, key_check, &game);
	mlx_loop_hook(game.mlx, anim, &game);
	mlx_loop(game.mlx);
	return (0);
}
