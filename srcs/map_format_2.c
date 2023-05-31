/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:24:33 by babreton          #+#    #+#             */
/*   Updated: 2023/03/22 10:36:04 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_minimal_lenght(t_window *win)
{
	if ((win->size.size_x < 4 && win->size.size_y < 3)
		|| (win->size.size_x < 3 && win->size.size_y < 4))
		check_error(2);
}
