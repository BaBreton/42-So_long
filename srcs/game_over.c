/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:37:20 by babreton          #+#    #+#             */
/*   Updated: 2023/03/25 13:45:32 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over_win(t_window *win)
{
	win->game_over = mlx_new_window(win->mlx, 256, 64, "Game Over !");
	put_image_2(win, OVER, 0, 0);
	mlx_hook(win->game_over, 17, 0, game_over_quit, win);
	mlx_key_hook(win->game_over, game_over_key, win);
}

int	game_over_key(int key, t_window *win)
{
	if (key == ENTER)
		game_over_quit(win);
	return (0);
}

int	game_over_quit(t_window *win)
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
	mlx_clear_window(win->mlx, win->game_over);
	mlx_destroy_window(win->mlx, win->game_over);
	destroy_images(win);
	destroy_images_2(win);
	mlx_destroy_display(win->mlx);
	win->ints.ingame = 0;
	free(win->mlx);
	exit(0);
	return (0);
}
