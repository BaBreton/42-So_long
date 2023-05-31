/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:09:18 by babreton          #+#    #+#             */
/*   Updated: 2023/03/23 20:24:30 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_window *win, int identifier, int x, int y)
{
	if (identifier == GROUND)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.ground, x, y);
	if (identifier == DOWN)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.p_down, x, y);
	if (identifier == UP)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.p_up, x, y);
	if (identifier == LEFT)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.p_left, x, y);
	if (identifier == RIGHT)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.p_right, x, y);
	if (identifier == T_LEFT)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.t_left, x, y);
	if (identifier == T_RIGHT)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.t_right, x, y);
	if (identifier == TOP)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.top, x, y);
	if (identifier == S_LEFT)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.left, x, y);
	if (identifier == S_RIGHT)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.right, x, y);
	if (identifier == B_RIGHT)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.b_right, x, y);
	if (identifier == B_LEFT)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.b_left, x, y);
}

void	put_image_2(t_window *win, int identifier, int x, int y)
{
	if (identifier == BOTTOM)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.bottom, x, y);
	if (identifier == EXIT)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.exit_e, x, y);
	if (identifier == CENTRAL)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.central, x, y);
	if (identifier == COLLECTIBLES)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.collec, x, y);
	if (identifier == BANNER)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.banner, x, y);
	if (identifier == EXIT_F)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.exit_f, x, y);
	if (identifier == END)
		mlx_put_image_to_window(win->mlx, win->exit_win, win->tiles.text, x, y);
	if (identifier == OVER)
		mlx_put_image_to_window(win->mlx, win->game_over, win->tiles.over,
			x, y);
	if (identifier == L_T)
		mlx_put_image_to_window(win->mlx, win->win, win->tiles.happy, x, y);
}

void	put_image_traps(t_window *win, int identifier, int x, int y)
{
	if (identifier == T01)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.t01, x, y);
	if (identifier == T02)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.t02, x, y);
	if (identifier == T03)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.t03, x, y);
	if (identifier == T04)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.t04, x, y);
	if (identifier == T05)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.t05, x, y);
	if (identifier == T06)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.t06, x, y);
	if (identifier == T07)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.t07, x, y);
	if (identifier == T08)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.t08, x, y);
}

void	put_image_traps_2(t_window *win, int identifier, int x, int y)
{
	if (identifier == T11)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.t11, x, y);
	if (identifier == T12)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.t12, x, y);
	if (identifier == T13)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.t13, x, y);
	if (identifier == T14)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.t14, x, y);
	if (identifier == T15)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.t15, x, y);
	if (identifier == T16)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.t16, x, y);
	if (identifier == T17)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.t17, x, y);
	if (identifier == T18)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.t18, x, y);
	if (identifier == T19)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.t19, x, y);
	if (identifier == T20)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.t20, x, y);
	if (identifier == DEAD)
		mlx_put_image_to_window(win->mlx, win->win, win->traps.dead, x, y);
}
