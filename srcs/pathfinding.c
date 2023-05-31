/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:58:48 by babreton          #+#    #+#             */
/*   Updated: 2023/03/27 16:20:03 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	duplicate_requirements(char *path, t_window *win)
{
	win->path.map = malloc(win->size.size_x * sizeof(char *));
	win->path.coord_x = 0;
	win->path.coord_y = 0;
	tab_init_2(path, win);
	win->path.coord_x = win->coord_x;
	win->path.coord_y = win->coord_y;
	win->path.max_moves = (win->size.size_x * win->size.size_y) * 4;
	win->path.nb_collectibles = win->ints.nb_collectibles;
	win->path.moves = 0;
	win->path.is_finishable = 0;
}

void	pathfinding(t_window *win)
{
	int	dir;
	int	i;
	int	path_return;

	i = -1;
	while (++i < 50000000 && win->path.is_finishable == 0)
	{
		dir = random_dir();
		if (dir == 1)
			path_return = path_check(win->path.coord_x,
					win->path.coord_y - 1, win);
		else if (dir == 2)
			path_return = path_check(win->path.coord_x - 1,
					win->path.coord_y, win);
		else if (dir == 3)
			path_return = path_check(win->path.coord_x,
					win->path.coord_y + 1, win);
		else if (dir == 4)
			path_return = path_check(win->path.coord_x + 1,
					win->path.coord_y, win);
		verif_dir(dir, path_return, win);
	}
}

int	random_dir(void)
{
	int	i;
	int	nb;

	i = -1;
	while (++i < 100)
		nb = (rand() % 4) + 1;
	return (nb);
}

int	path_check(int x, int y, t_window *win)
{
	if (win->path.map[y][x] == '1')
		return (0);
	else if (win->path.map[y][x] == '0' || win->path.map[y][x] == 'T')
		return (1);
	else if (win->path.map[y][x] == 'C')
	{
		win->path.map[y][x] = '0';
		win->path.nb_collectibles -= 1;
		return (1);
	}
	else if (win->path.map[y][x] == 'E' && win->path.nb_collectibles == 0)
		return (2);
	return (0);
}

void	verif_dir(int dir, int path_return, t_window *win)
{
	if (path_return == 1)
	{
		if (dir == 1)
			win->path.coord_y -= 1;
		else if (dir == 2)
			win->path.coord_x -= 1;
		else if (dir == 3)
			win->path.coord_y += 1;
		else if (dir == 4)
			win->path.coord_x += 1;
	}
	if (path_return == 2)
		win->path.is_finishable = 1;
}
