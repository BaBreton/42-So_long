/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:10:07 by babreton          #+#    #+#             */
/*   Updated: 2023/03/23 20:21:38 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_window *win)
{
	mlx_destroy_image(win->mlx, win->tiles.ground);
	mlx_destroy_image(win->mlx, win->tiles.p_down);
	mlx_destroy_image(win->mlx, win->tiles.p_right);
	mlx_destroy_image(win->mlx, win->tiles.p_left);
	mlx_destroy_image(win->mlx, win->tiles.p_up);
	mlx_destroy_image(win->mlx, win->tiles.happy);
	mlx_destroy_image(win->mlx, win->tiles.t_left);
	mlx_destroy_image(win->mlx, win->tiles.t_right);
	mlx_destroy_image(win->mlx, win->tiles.top);
	mlx_destroy_image(win->mlx, win->tiles.b_left);
	mlx_destroy_image(win->mlx, win->tiles.b_right);
	mlx_destroy_image(win->mlx, win->tiles.bottom);
	mlx_destroy_image(win->mlx, win->tiles.left);
	mlx_destroy_image(win->mlx, win->tiles.right);
	mlx_destroy_image(win->mlx, win->tiles.central);
	mlx_destroy_image(win->mlx, win->tiles.exit_e);
	mlx_destroy_image(win->mlx, win->tiles.exit_f);
	mlx_destroy_image(win->mlx, win->tiles.collec);
	mlx_destroy_image(win->mlx, win->tiles.text);
	mlx_destroy_image(win->mlx, win->tiles.banner);
	mlx_destroy_image(win->mlx, win->tiles.over);
	mlx_destroy_image(win->mlx, win->traps.t01);
	mlx_destroy_image(win->mlx, win->traps.t02);
	mlx_destroy_image(win->mlx, win->traps.t03);
	mlx_destroy_image(win->mlx, win->traps.t04);
}

void	destroy_images_2(t_window *win)
{
	mlx_destroy_image(win->mlx, win->traps.t05);
	mlx_destroy_image(win->mlx, win->traps.t06);
	mlx_destroy_image(win->mlx, win->traps.t07);
	mlx_destroy_image(win->mlx, win->traps.t08);
	mlx_destroy_image(win->mlx, win->traps.t11);
	mlx_destroy_image(win->mlx, win->traps.t12);
	mlx_destroy_image(win->mlx, win->traps.t13);
	mlx_destroy_image(win->mlx, win->traps.t14);
	mlx_destroy_image(win->mlx, win->traps.t15);
	mlx_destroy_image(win->mlx, win->traps.t16);
	mlx_destroy_image(win->mlx, win->traps.t17);
	mlx_destroy_image(win->mlx, win->traps.t18);
	mlx_destroy_image(win->mlx, win->traps.t19);
	mlx_destroy_image(win->mlx, win->traps.t20);
	mlx_destroy_image(win->mlx, win->traps.dead);
}
