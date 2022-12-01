/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:36:58 by bschweit          #+#    #+#             */
/*   Updated: 2022/07/27 15:48:46 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	message(BLUE"Game Closed !\n", game);
	map_destroy(game);
	exit(0);
}

void window_size(t_game *game, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		message(RED"Error open file !\n", game);

	game->size_x = (count_x(fd) * 48);
	game->size_y = (count_y(fd) * 48);
}

int	count_x(int fd)
{
	int		rd_byte;
	int		i;
	char	buffer[0];

	buffer[0] = '\0';
	rd_byte = 1;
	i = 0;
	while (rd_byte == 1)
	{
		rd_byte = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			i++;
		else
			break;
	}
	return (i);
}

int	count_y(int fd)
{
	int		rd_byte;
	char	buffer[0];
	int		i;

	rd_byte = 1;
	buffer[0] = '\0';
	i = 1;
	while (1)
	{
		rd_byte = read(fd, buffer, 1);
		if (rd_byte < 1)
			break;
		if (buffer[0] == '\n')
			i++;
	}
	return (i);
}

