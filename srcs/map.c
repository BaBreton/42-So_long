/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:09:56 by babreton          #+#    #+#             */
/*   Updated: 2023/03/25 14:21:06 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../includes/get_next_line.h"

void	load_map(char *path, t_window *win)
{
	integers_init(win);
	check_map_format(path, win);
	win->size.win_x = win->size.size_x * 32;
	win->size.win_y = win->size.size_y * 32;
	win->map = malloc(win->size.size_x * sizeof(char *));
	tab_init(path, win);
	win->coord_x = 0;
	win->coord_y = 0;
	get_player_coords(path, win);
	duplicate_requirements(path, win);
	window_init(path, win);
}

void	tab_init(char *path, t_window *win)
{
	char	*buffer;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	buffer = get_next_line(fd);
	i = -1;
	while (buffer[++i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			win->map[win->coord_y] = buffer;
			buffer = get_next_line(fd);
			win->coord_y += 1;
			i = -1;
		}
	}
	win->map[win->coord_y] = buffer;
	close(fd);
}

void	tab_init_2(char *path, t_window *win)
{
	char	*buffer;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	buffer = get_next_line(fd);
	i = -1;
	while (buffer[++i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			win->path.map[win->path.coord_y] = buffer;
			buffer = get_next_line(fd);
			win->path.coord_y += 1;
			i = -1;
		}
	}
	win->path.map[win->path.coord_y] = buffer;
	close(fd);
}

void	get_player_coords(char *path, t_window *win)
{
	char	*buffer;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	buffer = (char *)malloc((MAX_MAP_SIZE + 1) * sizeof(char));
	read(fd, buffer, (MAX_MAP_SIZE + 1));
	i = -1;
	while (buffer[++i] != 'P')
	{
		if (buffer[i] == '\n')
		{
			win->coord_x = 0;
			win->coord_y += 1;
		}
		win->coord_x += 1;
	}
	win->coord_x -= 1;
	free(buffer);
	close(fd);
}
