/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:19:03 by babreton          #+#    #+#             */
/*   Updated: 2023/03/22 17:08:29 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../includes/get_next_line.h"

void	check_map_format(char *path, t_window *win)
{
	char	*buffer;
	int		fd;
	int		bytes_read;

	fd = open(path, O_RDONLY);
	if (fd < 1)
		check_error(7);
	buffer = (char *)malloc((MAX_MAP_SIZE + 1) * sizeof(char));
	bytes_read = read(fd, buffer, (MAX_MAP_SIZE + 1));
	buffer[bytes_read] = '\0';
	check_map_lenght(buffer, bytes_read, win);
	check_map_wall(buffer);
	check_map_square(buffer, win);
	check_map_requirements(buffer, win);
	free(buffer);
	close(fd);
}

void	check_map_lenght(char *buffer, int bytes_read, t_window *win)
{
	int		count;
	int		first_line;

	if (bytes_read == MAX_MAP_SIZE + 1)
		check_error(1);
	count = -1;
	first_line = 0;
	while (buffer[++count] != '\0')
	{
		if (buffer[count] == '\n' && first_line == 0)
		{
			first_line = 1;
			win->size.size_x = count;
			win->size.size_y = 1;
		}
		if (buffer[count] == '\n')
			win->size.size_y += 1;
	}
	check_minimal_lenght(win);
}

void	check_map_wall(char *buffer)
{
	int	i;
	int	first_line;

	i = 0;
	first_line = 0;
	while (buffer[++i] != '\0')
	{
		while (buffer[i] != '\n' && first_line == 0)
		{
			if (buffer[i] != '1')
				check_error(3);
			i++;
		}
		first_line = 1;
		if (buffer[i] == '\n')
			if (buffer[i + 1] != '1' || buffer[i - 1] != '1')
				check_error(3);
	}
	while (buffer[--i] != '\n')
		if (buffer[i] != '1')
			check_error(3);
}

void	check_map_square(char *buffer, t_window *win)
{
	int	i;
	int	cmp;

	i = 0;
	cmp = 0;
	while (buffer[i] != '\0')
	{
		while (buffer[i] != '\n' && buffer[i] != '\0')
		{
			i++;
			cmp++;
		}
		if (cmp != win->size.size_x)
			check_error(4);
		if (buffer[i] == '\n')
			i++;
		cmp = 0;
	}
}

void	check_map_requirements(char *buffer, t_window *win)
{
	int	i;
	int	p;
	int	e;

	i = -1;
	p = 1;
	e = 1;
	while (buffer[++i] != '\0')
	{
		if (buffer[i] == 'P')
			p -= 1;
		if (buffer[i] == 'E')
			e -= 1;
		if (buffer[i] == 'C')
			win->ints.nb_collectibles += 1;
	}
	if (p != 0 || e != 0)
		check_error(5);
}
