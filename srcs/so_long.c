/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:08:01 by babreton          #+#    #+#             */
/*   Updated: 2023/03/25 13:31:50 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_window	win;
	char		*path;

	path = argv[1];
	if (argc < 2)
		path = menu();
	ft_printf("\033[0m\n");
	ft_printf("\e[1;1H\e[2J");
	load_map(path, &win);
	srand(time(NULL));
	pathfinding(&win);
	if (win.path.is_finishable == 0)
		check_error(8);
	put_tiles(&win);
	mlx_loop_hook(win.mlx, anim_traps, &win);
	mlx_loop(win.mlx);
	return (0);
}
