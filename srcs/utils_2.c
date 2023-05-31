/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:29:41 by babreton          #+#    #+#             */
/*   Updated: 2023/03/23 20:28:19 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../includes/get_next_line.h"

int	count_digits(int n)
{
	int	count;

	count = (n == 0);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		len;

	sign = (n < 0);
	len = count_digits(n);
	if (sign)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > sign)
	{
		str[len] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

char	*menu(void)
{
	char	*answer;

	ft_printf("\e[1;1H\e[2J");
	ft_printf("  \033[47;34m Bienvenue sur So_long \033[0m\n");
	ft_printf("\033[47;34m Veuillez choisir une map :  \033[0m\n");
	ft_printf("\033[44;37m 1 : map.ber                 \033[0m\n");
	ft_printf("\033[44;37m 2 : test.ber                \033[0m\n");
	ft_printf("\033[44;37m 3 : big.ber                 \033[0m\n");
	ft_printf("\033[44;37m 4 : Nouvelle map            \033[0m\n");
	ft_printf("\033[47;30m");
	answer = get_next_line(0);
	if (answer[0] == '1')
		return ("./maps/map.ber");
	if (answer[0] == '2')
		return ("./maps/test.ber");
	if (answer[0] == '3')
		return ("./maps/big.ber");
	if (answer[0] == '4')
	{
		ft_printf("Merci d'indiquer le chemin vers la nouvelle map : ");
		answer = get_next_line(0);
	}
	answer = check_format(answer);
	ft_printf(" \033[0m\n");
	return (answer);
}

char	*check_format(char	*answer)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(answer);
	str = (char *)malloc((len - 1) * sizeof(char));
	while (answer[i])
	{
		if (answer[i] == '\n')
			break ;
		str[i] = answer[i];
		i++;
	}
	str[i] = '\0';
	ft_printf(" \033[0m\n");
	ft_printf("\e[1;1H\e[2J");
	if (str[i - 1] != 'r' || str[i - 2] != 'e'
		|| str[i - 3] != 'b' || str[i - 4] != '.')
		check_error(8);
	return (str);
}

void	check_exit(t_window *win)
{
	if (win->ints.nb_collectibles != 0)
		check_error(6);
	else
	{
		win->ints.ingame = 0;
		put_image(win, GROUND, win->coord_x * 32, win->coord_y * 32);
		exit_win(win);
	}
}
