/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:29:31 by bschweit          #+#    #+#             */
/*   Updated: 2022/07/28 05:55:19 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#define BLUE "\033[1m\033[34m"
#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define SIZE 48
#define	UP 13
#define DOWN 1
#define LEFT 0
#define RIGHT 2
#define ESC 53
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "mlx/mlx.h"

typedef struct s_player
{
	int	x;
	int	y;
	int	coin;
	int	mouvement;
}		t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			size_x;
	int			size_y;
	int			coincheck;
	int			coin_x;
	int			coin_y;
	int			exitcheck;
	int			playercheck;
	t_player	player;
}				t_game;

typedef struct s_image
{
	void			*img;
	int				img_width;
	struct  s_game	wlx;
	int				img_heigth;
	char			*relative_path;
}					t_image;

typedef struct s_block
{
	char	*name;
	char	*relative_path;
}			t_block;

int		move_check(t_game *game, int y, int x);
void	up(t_game *game);
void	down(t_game *game);
void	left(t_game *game);
void	right(t_game *game);
void	moove(t_game *game);
void	game_control(t_game *game);
void	map_control(t_game *game);
void	wall_control(t_game *game);
int		destroy_window(t_game *game);
void	message(char *str, t_game *game);
void	map_destroy(t_game *game);
void	window_size(t_game *game, char **argv);
int		count_x(int fd);
int		count_y(int fd);
void	*get_next_line(int fd);
void	*myfree(void *str);
void	create_map(t_game *game, char **argv);
void	fill_map(char *line, t_game *game, int y);
void	*put_image(t_image image, int x, int y);
void	create_floor(t_game game, int y);
t_block	set_block(char name);
void	create_all(t_game *game, int y);
void	put_ctl(t_game *game);
void	put_ctr(t_game *game);
void	put_cdl(t_game *game);
void	put_cdr(t_game *game);
void	put_vertical(t_game *game);
void	put_horizontal(t_game *game);


#endif
