/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:09:27 by babreton          #+#    #+#             */
/*   Updated: 2023/03/25 13:46:33 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	anim_traps(t_window *win)
{
	char	*str;
	char	*nbr;

	nbr = ft_itoa(win->ints.move_count);
	str = win_title("Nombre de mouvements : ", nbr);
	put_image_2(win, BANNER, 8, 8);
	mlx_string_put(win->mlx, win->win, 16, 24, 0x000000, str);
	free(nbr);
	free(str);
	if (win->map[win->coord_y][win->coord_x] == 'T' && win->ints.traps_on == 1)
	{
		win->ints.ingame = 0;
		win->ints.traps_on = -1;
		put_image_traps_2(win, DEAD, win->coord_x * 32, win->coord_y * 32);
		game_over_win(win);
	}
	random_number(win);
	if (win->ints.traps_on == 1)
		traps_loop_on(win);
	if (win->ints.traps_on == 0)
		traps_loop_off(win);
	return (0);
}

void	random_number(t_window *win)
{
	static int	last;
	time_t		current_time;
	int			random;

	current_time = time(NULL);
	srand((unsigned int) current_time);
	random = rand();
	if (win->ints.traps_on == -1)
		return ;
	if (random % 2 == 0 && last % 2 == 0)
		win->ints.traps_on = 1;
	if (random % 2 != 0 && last % 2 != 0)
		win->ints.traps_on = 0;
	last = random;
}

void	traps_loop_on(t_window *win)
{
	win->ints.time += 1;
	if (win->ints.identifier == T20)
		win->ints.identifier = T11;
	if (win->ints.time == 1000)
	{
		win->ints.identifier += 1;
		win->ints.time = 0;
	}
	loop(win);
}

void	traps_loop_off(t_window *win)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (win->map[win->coord_y][win->coord_x] == 'T')
		put_image_2(win, L_T, win->coord_x * 32, win->coord_y * 32);
	else
	{
		while (++j < win->size.size_y && i < win->size.size_x)
		{
			while (++i < win->size.size_x)
				if (win->map[j][i] == 'T')
					put_image_traps(win, T01, i * 32, j * 32);
		i = -1;
		}
	}
}

void	loop(t_window *win)
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
				if (win->ints.identifier > 57 && win->ints.identifier < 68)
					put_image_traps_2(win, win->ints.identifier,
						i * 32, j * 32);
				else
					put_image_traps(win, win->ints.identifier, i * 32, j * 32);
			}
		}
		i = -1;
	}
}
