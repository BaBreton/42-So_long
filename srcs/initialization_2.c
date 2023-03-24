/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:23:03 by babreton          #+#    #+#             */
/*   Updated: 2023/03/23 20:30:07 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tiles_init_2(int i, t_window *win)
{
	win->tiles.right = mlx_xpm_file_to_image(win->mlx, "./tileset/R.xpm",
			&i, &i);
	win->tiles.central = mlx_xpm_file_to_image(win->mlx, "./tileset/W_C.xpm",
			&i, &i);
	win->tiles.ground = mlx_xpm_file_to_image(win->mlx, "./tileset/G.xpm",
			&i, &i);
	win->tiles.exit_e = mlx_xpm_file_to_image(win->mlx, "./tileset/E_E.xpm",
			&i, &i);
	win->tiles.exit_f = mlx_xpm_file_to_image(win->mlx, "./tileset/E_F.xpm",
			&i, &i);
	win->tiles.collec = mlx_xpm_file_to_image(win->mlx, "./tileset/C.xpm",
			&i, &i);
	win->tiles.text = mlx_xpm_file_to_image(win->mlx, "./tileset/t.xpm",
			&i, &i);
	win->tiles.banner = mlx_xpm_file_to_image(win->mlx, "./tileset/ban.xpm",
			&i, &i);
	win->tiles.over = mlx_xpm_file_to_image(win->mlx, "./tileset/G-O.xpm",
			&i, &i);
}

void	traps_init_2(int i, t_window *win)
{
	win->traps.t15 = mlx_xpm_file_to_image(win->mlx, "./tileset/T15.xpm",
			&i, &i);
	win->traps.t16 = mlx_xpm_file_to_image(win->mlx, "./tileset/T16.xpm",
			&i, &i);
	win->traps.t17 = mlx_xpm_file_to_image(win->mlx, "./tileset/T17.xpm",
			&i, &i);
	win->traps.t18 = mlx_xpm_file_to_image(win->mlx, "./tileset/T18.xpm",
			&i, &i);
	win->traps.t19 = mlx_xpm_file_to_image(win->mlx, "./tileset/T19.xpm",
			&i, &i);
	win->traps.t20 = mlx_xpm_file_to_image(win->mlx, "./tileset/T20.xpm",
			&i, &i);
	win->traps.dead = mlx_xpm_file_to_image(win->mlx, "./tileset/D.xpm",
			&i, &i);
}
