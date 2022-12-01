/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:33:29 by bschweit          #+#    #+#             */
/*   Updated: 2022/07/28 03:51:12 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*put_image(t_image image, int x, int y)
{
	image.img = mlx_xpm_file_to_image(image.wlx.mlx, 
			image.relative_path, &image.img_width, &image.img_heigth);
	mlx_put_image_to_window(image.wlx.mlx, image.wlx.win, image.img, x, y);
	return (image.img);
}

t_block set_block(char name)
{
	t_block	maps[7];
	int		i;

	maps[0] = (t_block){"1", "./img/plant.xpm"};
	maps[1] = (t_block){"0", "./img/sol.xpm"};
	maps[2] = (t_block){"C", "./img/chest.xpm"};
	maps[3] = (t_block){"P", "./img/down_c.xpm"};
	maps[4] = (t_block){"E", "./img/exit.xpm"};
	maps[5] = (t_block){NULL, NULL};
	i = 0;
	while (maps[i].name != NULL)
	{
		if (maps[i].name[0] == name)
		{
			return (maps[i]);
			break;
		}
		i++;
	}
	return (maps[5]);;
}
