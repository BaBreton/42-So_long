/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:37:15 by babreton          #+#    #+#             */
/*   Updated: 2023/03/25 13:48:00 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tiles(t_window *win)
{
	tiles_board(win);
	put_ground(win);
	put_traps(win);
	put_wall(win);
}

void	put_ground(t_window *win)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < win->size.size_y && i < win->size.size_x)
	{
		while (++i < win->size.size_x)
		{
			if (win->map[j][i] == '0')
				put_image(win, GROUND, i * 32, j * 32);
			if (win->map[j][i] == 'E')
				put_image_2(win, EXIT, i * 32, j * 32);
			if (win->map[j][i] == 'C')
				put_image_2(win, COLLECTIBLES, i * 32, j * 32);
			if (win->map[j][i] == 'P')
			{
				put_image(win, DOWN, i * 32, j * 32);
				win->map[j][i] = '0';
			}
			if (win->map[j][i] == '1')
				put_image_2(win, CENTRAL, i * 32, j * 32);
		}
		i = -1;
	}
}

void	put_traps(t_window *win)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < win->size.size_y && i < win->size.size_x)
	{
		while (++i < win->size.size_x)
		{
			if (win->map[j][i] == 'T')
			{
				put_image_traps(win, T01, i * 32, j * 32);
				win->ints.nb_traps += 1;
			}
		}
		i = -1;
	}
}

void	put_wall(t_window *win)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	put_image(win, T_LEFT, i, 0);
	while (++i < win->size.size_x - 1)
		put_image(win, TOP, i * 32, 0);
	put_image(win, T_RIGHT, i * 32, 0);
	x = i;
	i = 0;
	while (++i < win->size.size_y -1)
		put_image(win, S_RIGHT, x * 32, i * 32);
	put_image(win, B_RIGHT, x * 32, i * 32);
	while (--x != 0)
		put_image_2(win, BOTTOM, x * 32, i * 32);
	put_image(win, B_LEFT, x * 32, i * 32);
	while (--i != 0)
		put_image(win, S_LEFT, x * 32, i * 32);
}
