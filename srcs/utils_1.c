/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:34:14 by babreton          #+#    #+#             */
/*   Updated: 2023/03/23 20:21:01 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../includes/get_next_line.h"

char	*win_title(char *s1, char *s2)
{
	size_t	i;
	int		len;
	char	*array;

	i = 0;
	len = ft_strlen(s2);
	len = len + ft_strlen(s1);
	array = (char *)malloc(sizeof(char) * (len + 1));
	if (!array)
		return (NULL);
	len = 0;
	while (s1[i])
		array[len++] = s1[i++];
	i = 0;
	while (s2[i])
		array[len++] = s2[i++];
	array[len] = '\0';
	return (array);
}

void	check_trap(int identifier, t_window *win)
{
	if (identifier == DOWN)
	{
		put_image(win, GROUND, win->coord_x * 32, win->coord_y * 32);
		win->coord_y += 1;
		put_image_traps_2(win, L_T, win->coord_x * 32, win->coord_y * 32);
		win->ints.move_count += 1;
		return ;
	}
	if (identifier == UP)
	{
		put_image(win, GROUND, win->coord_x * 32, win->coord_y * 32);
		win->coord_y -= 1;
		put_image_traps_2(win, L_T, win->coord_x * 32, win->coord_y * 32);
		win->ints.move_count += 1;
		return ;
	}
}

void	check_trap_2(int identifier, t_window *win)
{
	if (identifier == RIGHT)
	{
		put_image(win, GROUND, win->coord_x * 32, win->coord_y * 32);
		win->coord_x += 1;
		put_image_traps_2(win, L_T, win->coord_x * 32, win->coord_y * 32);
		win->ints.move_count += 1;
		return ;
	}
	if (identifier == LEFT)
	{
		put_image(win, GROUND, win->coord_x * 32, win->coord_y * 32);
		win->coord_x -= 1;
		put_image_traps_2(win, L_T, win->coord_x * 32, win->coord_y * 32);
		win->ints.move_count += 1;
		return ;
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	desallocate(t_window *win)
{
	int		i;

	i = -1;
	ft_printf("%d", sizeof(win->map));
	while (++i < win->size.size_x)
	{
		free(win->map[i]);
		win->map[i] = NULL;
	}
	ft_printf("%d", sizeof(win->map));
	free(win->map);
}
