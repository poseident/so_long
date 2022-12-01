/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:30:44 by bschweit          #+#    #+#             */
/*   Updated: 2022/07/28 02:58:42 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update(t_game *game, int x, int y)
{
	t_image	image;

	image.relative_path = "./img/sol.xpm";
	image.wlx = *game;
	put_image(image, game->player.x, game->player.y);
	put_image(image, x, y);
}

void	right(t_game *game)
{
	int	y;
	int	x;
	t_image	image;

	image.relative_path = "./img/right_c.xpm";
	image.wlx = *game;
	y = game->player.y;
	x = game->player.x + 48;
	if ((move_check(game, (y / 48), (x / 48)) != 1))
	{
		moove(game);
		update(game, x, y);
		game->player.y = y;
		game->player.x = x;
		put_image(image, x, y);
	}
}

void	moove(t_game *game)
{
	game->player.mouvement++;
	ft_printf(GREEN"Move count : %d\n", game->player.mouvement);
}

void	left(t_game *game)
{
	int	y;
	int	x;
	t_image	image;

	image.relative_path = "./img/left_c.xpm";
	image.wlx = *game;
	y = game->player.y;
	x = game->player.x - 48;
	if ((move_check(game, (y / 48), (x / 48)) != 1))
	{
		moove(game);
		update(game, x, y);
		game->player.y = y;
		game->player.x = x;
		put_image(image, x, y);
	}
}

void    down(t_game *game)
{
    int y;
    int x;
    t_image image;

    image.relative_path = "./img/down_c.xpm";
    image.wlx = *game;
    y = game->player.y + 48;
    x = game->player.x;
    if ((move_check(game, (y / 48), (x / 48)) != 1))
    {
        moove(game);
        update(game, x, y);
        game->player.y = y;
        game->player.x = x;
        put_image(image, x, y);
    }
}

void    up(t_game *game)
{
    int y;
    int x;
    t_image image;

    image.relative_path = "./img/up_c.xpm";
    image.wlx = *game;
    y = game->player.y - 48;
    x = game->player.x;
    if ((move_check(game, (y / 48), (x / 48)) != 1))
    {
        moove(game);
        update(game, x, y);
        game->player.y = y;
        game->player.x = x;
        put_image(image, x, y);
    }
}
