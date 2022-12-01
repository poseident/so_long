/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:04:32 by bschweit          #+#    #+#             */
/*   Updated: 2022/07/28 02:00:39 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_destroy(t_game *game)
{
	int	y;

	y = 0;
	while (game->map[y])
	{
		free(game->map[y]);
		y++;
	}
}

void	create_all(t_game *game, int y)
{
	int	j;
	t_block	map;
	t_image	image;

	image.wlx = *game;
	j = 0;
	while (game->map[y])
	{
		while (game->map[y][j])
		{
			map = set_block(game->map[y][j]);
			image.relative_path = map.relative_path;
			put_image(image, (j * SIZE), (y * SIZE));
			j++;
		}
		y++;
	}
}

void	create_floor(t_game game, int y)
{
	int		h;
	t_image	image;

	image.wlx = game;
	image.relative_path = "./img/sol.xpm";
	while (game.map[y])
	{
		h = 0;
		while (game.map[y][h])
		{
			put_image(image, (h * SIZE), (y * SIZE));
			h++;
		}
		y++;
	}
}	
		
void	fill_map(char *line, t_game *game, int y)
{
	int		i;
	t_image	image;

	image.wlx = *game;
	i = 0;
	game->map[y] = (char *)malloc(sizeof(char) * 22);
	while (line[i])
	{
		if (line[i] == '\n')
			break;
		game->map[y][i] = line[i];
		i++;
	}
	create_floor(*game, y);
	create_all(game, y);
}

void	create_map(t_game *game, char **argv)
{
	int		y;
	char	*line;
	int		fd;

	game->map = (char **)malloc(sizeof(char*) * 9999);
	fd = open(argv[1], O_RDONLY);
	y = 0;
	while (y <= game->size_y / 48)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		fill_map(line, game, y);
		y++;
	}
	close(fd);
}
