/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:19:20 by babreton          #+#    #+#             */
/*   Updated: 2023/03/22 21:44:59 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keys(int key, t_window *win)
{
	ft_printf("\e[1;1H\e[2J");
	if (win->ints.ingame == 1)
	{
		if (key == DOWN || key == S)
			down_event(win);
		if (key == UP || key == Z)
			up_event(win);
		if (key == LEFT || key == Q)
			left_event(win);
		if (key == RIGHT || key == D)
			right_event(win);
	}
	if (key == ESCAPE)
		quit(win);
	ft_printf("\033[0m");
	if (win->ints.nb_collectibles == 0)
		change_exit(win);
	return (0);
}

void	down_event(t_window *win)
{
	if (win->map[win->coord_y + 1][win->coord_x] == '1')
		return ((void)put_image(win, DO, win->coord_x * 32, win->coord_y * 32));
	if (win->map[win->coord_y + 1][win->coord_x] == '0')
	{
		put_image(win, GROUND, win->coord_x * 32, win->coord_y * 32);
		win->coord_y += 1;
		put_image(win, DOWN, win->coord_x * 32, win->coord_y * 32);
		win->ints.move_count += 1;
		return ;
	}
	if (win->map[win->coord_y + 1][win->coord_x] == 'C')
	{
		put_image(win, GROUND, win->coord_x * 32, win->coord_y * 32);
		win->coord_y += 1;
		win->map[win->coord_y][win->coord_x] = '0';
		put_image(win, DOWN, win->coord_x * 32, win->coord_y * 32);
		win->ints.move_count += 1;
		win->ints.nb_collectibles -= 1;
		return ;
	}
	if (win->map[win->coord_y + 1][win->coord_x] == 'E')
		check_exit(win);
	if (win->map[win->coord_y + 1][win->coord_x] == 'T')
		check_trap(DOWN, win);
}

void	up_event(t_window *win)
{
	if (win->map[win->coord_y - 1][win->coord_x] == '1')
		return ((void)put_image(win, UP, win->coord_x * 32, win->coord_y * 32));
	if (win->map[win->coord_y - 1][win->coord_x] == '0')
	{
		put_image(win, GROUND, win->coord_x * 32, win->coord_y * 32);
		win->coord_y -= 1;
		put_image(win, UP, win->coord_x * 32, win->coord_y * 32);
		win->ints.move_count += 1;
		return ;
	}
	if (win->map[win->coord_y - 1][win->coord_x] == 'C')
	{
		put_image(win, GROUND, win->coord_x * 32, win->coord_y * 32);
		win->coord_y -= 1;
		win->map[win->coord_y][win->coord_x] = '0';
		put_image(win, UP, win->coord_x * 32, win->coord_y * 32);
		win->ints.move_count += 1;
		win->ints.nb_collectibles -= 1;
		return ;
	}
	if (win->map[win->coord_y - 1][win->coord_x] == 'E')
		check_exit(win);
	if (win->map[win->coord_y - 1][win->coord_x] == 'T')
		check_trap(UP, win);
}

void	right_event(t_window *win)
{
	if (win->map[win->coord_y][win->coord_x + 1] == '1')
		return ((void)put_image(win, RI, win->coord_x * 32, win->coord_y * 32));
	if (win->map[win->coord_y][win->coord_x + 1] == '0')
	{
		put_image(win, GROUND, win->coord_x * 32, win->coord_y * 32);
		win->coord_x += 1;
		put_image(win, RIGHT, win->coord_x * 32, win->coord_y * 32);
		win->ints.move_count += 1;
		return ;
	}
	if (win->map[win->coord_y][win->coord_x + 1] == 'C')
	{
		put_image(win, GROUND, win->coord_x * 32, win->coord_y * 32);
		win->coord_x += 1;
		win->map[win->coord_y][win->coord_x] = '0';
		put_image(win, RIGHT, win->coord_x * 32, win->coord_y * 32);
		win->ints.move_count += 1;
		win->ints.nb_collectibles -= 1;
		return ;
	}
	if (win->map[win->coord_y][win->coord_x + 1] == 'E')
		check_exit(win);
	if (win->map[win->coord_y][win->coord_x + 1] == 'T')
		check_trap_2(RIGHT, win);
}

void	left_event(t_window *win)
{
	if (win->map[win->coord_y][win->coord_x - 1] == '1')
		return ((void)put_image(win, LE, win->coord_x * 32, win->coord_y * 32));
	if (win->map[win->coord_y][win->coord_x - 1] == '0')
	{
		put_image(win, GROUND, win->coord_x * 32, win->coord_y * 32);
		win->coord_x -= 1;
		put_image(win, LEFT, win->coord_x * 32, win->coord_y * 32);
		win->ints.move_count += 1;
		return ;
	}
	if (win->map[win->coord_y][win->coord_x - 1] == 'C')
	{
		put_image(win, GROUND, win->coord_x * 32, win->coord_y * 32);
		win->coord_x -= 1;
		win->map[win->coord_y][win->coord_x] = '0';
		put_image(win, LEFT, win->coord_x * 32, win->coord_y * 32);
		win->ints.move_count += 1;
		win->ints.nb_collectibles -= 1;
		return ;
	}
	if (win->map[win->coord_y][win->coord_x - 1] == 'E')
		check_exit(win);
	if (win->map[win->coord_y][win->coord_x - 1] == 'T')
		check_trap_2(LEFT, win);
}
