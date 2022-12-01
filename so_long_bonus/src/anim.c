/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 05:47:26 by bschweit          #+#    #+#             */
/*   Updated: 2022/07/28 05:55:02 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_anim(t_game *game)
{
	int	i;


int	anim(t_game *game)
{
	game->enemyspeed++;
	if (game->enemyspeed >= 3000)
	{
		move_anim(game);
		game->enemyspeed(0);
	}
	return (0);
}
