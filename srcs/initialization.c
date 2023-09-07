/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:11:44 by babreton          #+#    #+#             */
/*   Updated: 2023/09/07 13:49:38 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	integers_init(t_window *win)
{
	win->ints.move_count = 0;
	win->ints.nb_collectibles = 0;
	win->ints.nb_traps = 0;
	win->ints.time = 0;
	win->ints.identifier = T01;
	win->ints.traps_on = 1;
	win->ints.ingame = 1;
	win->coord_x = 0;
	win->coord_y = 0;
}

void	window_init(char *path, t_window *win)
{
	path = win_title("Map : ", path);
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->size.win_x, win->size.win_y, path);
	free(path);
	mlx_key_hook(win->win, keys, win);
	mlx_hook(win->win, 17, 0, quit, win);
	if (win->ints.ingame == 0)
		desallocate(win);
}

void	tiles_board(t_window *win)
{
	tiles_init(32, win);
	traps_init(32, win);
}

void	tiles_init(int i, t_window	*win)
{
	win->tiles.p_up = mlx_xpm_file_to_image(win->mlx, "./tileset/P_U.xpm",
			&i, &i);
	win->tiles.p_down = mlx_xpm_file_to_image(win->mlx, "./tileset/P_D.xpm",
			&i, &i);
	win->tiles.p_right = mlx_xpm_file_to_image(win->mlx, "./tileset/P_R.xpm",
			&i, &i);
	win->tiles.p_left = mlx_xpm_file_to_image(win->mlx, "./tileset/P_L.xpm",
			&i, &i);
	win->tiles.happy = mlx_xpm_file_to_image(win->mlx, "./tileset/L_T.xpm",
			&i, &i);
	win->tiles.t_left = mlx_xpm_file_to_image(win->mlx, "./tileset/T_L.xpm",
			&i, &i);
	win->tiles.t_right = mlx_xpm_file_to_image(win->mlx, "./tileset/T_R.xpm",
			&i, &i);
	win->tiles.top = mlx_xpm_file_to_image(win->mlx, "./tileset/TB.xpm",
			&i, &i);
	win->tiles.b_left = mlx_xpm_file_to_image(win->mlx, "./tileset/B_L.xpm",
			&i, &i);
	win->tiles.b_right = mlx_xpm_file_to_image(win->mlx, "./tileset/B_R.xpm",
			&i, &i);
	win->tiles.bottom = mlx_xpm_file_to_image(win->mlx, "./tileset/B.xpm",
			&i, &i);
	win->tiles.left = mlx_xpm_file_to_image(win->mlx, "./tileset/L.xpm",
			&i, &i);
	tiles_init_2(i, win);
}

void	traps_init(int i, t_window *win)
{
	win->traps.t01 = mlx_xpm_file_to_image(win->mlx, "./tileset/T01.xpm",
			&i, &i);
	win->traps.t02 = mlx_xpm_file_to_image(win->mlx, "./tileset/T02.xpm",
			&i, &i);
	win->traps.t03 = mlx_xpm_file_to_image(win->mlx, "./tileset/T03.xpm",
			&i, &i);
	win->traps.t04 = mlx_xpm_file_to_image(win->mlx, "./tileset/T04.xpm",
			&i, &i);
	win->traps.t05 = mlx_xpm_file_to_image(win->mlx, "./tileset/T05.xpm",
			&i, &i);
	win->traps.t06 = mlx_xpm_file_to_image(win->mlx, "./tileset/T06.xpm",
			&i, &i);
	win->traps.t07 = mlx_xpm_file_to_image(win->mlx, "./tileset/T07.xpm",
			&i, &i);
	win->traps.t08 = mlx_xpm_file_to_image(win->mlx, "./tileset/T08.xpm",
			&i, &i);
	win->traps.t11 = mlx_xpm_file_to_image(win->mlx, "./tileset/T11.xpm",
			&i, &i);
	win->traps.t12 = mlx_xpm_file_to_image(win->mlx, "./tileset/T12.xpm",
			&i, &i);
	win->traps.t13 = mlx_xpm_file_to_image(win->mlx, "./tileset/T13.xpm",
			&i, &i);
	win->traps.t14 = mlx_xpm_file_to_image(win->mlx, "./tileset/T14.xpm",
			&i, &i);
	traps_init_2(i, win);
}
