/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:34:38 by babreton          #+#    #+#             */
/*   Updated: 2023/03/25 13:47:29 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_win(t_window *win)
{
	win->exit_win = mlx_new_window(win->mlx, 256, 64, "Fini !");
	put_image_2(win, END, 0, 0);
	mlx_hook(win->exit_win, 17, 0, exit_quit, win);
	mlx_key_hook(win->exit_win, exit_key, win);
}

int	exit_key(int key, t_window *win)
{
	if (key == ENTER)
		exit_quit(win);
	return (0);
}

int	exit_quit(t_window *win)
{
	int		i;

	i = -1;
	while (++i < win->size.size_y)
	{
		free(win->map[i]);
		free(win->path.map[i]);
	}
	free(win->map);
	free(win->path.map);
	mlx_clear_window(win->mlx, win->win);
	mlx_destroy_window(win->mlx, win->win);
	mlx_clear_window(win->mlx, win->exit_win);
	mlx_destroy_window(win->mlx, win->exit_win);
	destroy_images(win);
	destroy_images_2(win);
	mlx_destroy_display(win->mlx);
	win->ints.ingame = 0;
	free(win->mlx);
	exit(0);
	return (0);
}

void	change_exit(t_window *win)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < win->size.size_y && i < win->size.size_x)
	{
		while (++i < win->size.size_x)
			if (win->map[j][i] == 'E')
				put_image_2(win, EXIT_F, i * 32, j * 32);
		i = -1;
	}
}

int	quit(t_window *win)
{
	int		i;

	i = -1;
	while (++i < win->size.size_y)
	{
		free(win->map[i]);
		free(win->path.map[i]);
	}
	free(win->map);
	free(win->path.map);
	mlx_clear_window(win->mlx, win->win);
	mlx_destroy_window(win->mlx, win->win);
	destroy_images(win);
	destroy_images_2(win);
	mlx_destroy_display(win->mlx);
	win->ints.ingame = 0;
	free(win->mlx);
	exit(0);
	return (0);
}
