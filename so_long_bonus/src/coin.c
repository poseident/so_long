/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 21:44:16 by bschweit          #+#    #+#             */
/*   Updated: 2022/07/28 00:59:04 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_ctl(t_game *game)
{
	t_image	image;

	image.wlx = *game;
	image.relative_path = "./img/ctl.xpm";
	put_image(image, (0 * SIZE), (0 * SIZE));
	put_ctr(game);
}

void	put_ctr(t_game *game)
{
	t_image	image;

	image.wlx = *game;
	image.relative_path = "./img/ctr.xpm";
	put_image(image, ((game->size_x / 48 - 1) * SIZE), (0 * SIZE));
	put_cdl(game);
}

void	put_cdl(t_game *game)
{
	t_image	image;

	image.wlx = *game;
	image.relative_path = "./img/cdl.xpm";
	put_image(image, (0 * SIZE), ((game->size_y / 48 - 1) * SIZE));
	put_cdr(game);
}

void	put_cdr(t_game *game)
{
	t_image	image;
	int		k;

	k = game->size_x / 48 - 1;
	image.wlx = *game;
	image.relative_path = "./img/cdr.xpm";
	put_image(image, (k * SIZE), ((game->size_y / 48 - 1) * SIZE));
	put_vertical(game);
}

void	put_vertical(t_game *game)
{
	int		y;
	t_image	image;

	image.wlx = *game;
	image.relative_path = "./img/vertical.xpm";
	y = 1;
	while (y < ((game->size_y / 48) - 1))
	{
		put_image(image, (0 * SIZE), (y * SIZE));
		put_image(image, ((game->size_x / 48 - 1) * SIZE), (y * SIZE));
		y++;
	}
	put_horizontal(game);
}

void	put_horizontal(t_game *game)
{
	int	x;
	t_image	image;

	image.wlx = *game;
	image.relative_path = "./img/wall.xpm";
	x = 1;
	while (x < ((game->size_x / 48) - 1))
	{
		put_image(image, (x * SIZE), (0 * SIZE));
		put_image(image, (x * SIZE), (game->size_y / 48 - 1) * SIZE);
		x++;
	}
}
