/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:02:29 by babreton          #+#    #+#             */
/*   Updated: 2023/03/22 14:02:32 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_error(int error)
{
	if (error == 1)
		print_error_1(1);
	if (error == 2)
		print_error_3(2);
	if (error == 3)
		print_error_3(1);
	if (error == 4)
		print_error_2(2);
	if (error == 5)
		print_error_2(1);
	if (error == 6)
		print_error_1(2);
	if (error == 7)
		print_error_4(1);
	if (error == 8)
		print_error_4(2);
}

void	print_error_1(int error)
{
	ft_printf("\033[38;5;208m");
	if (error == 1)
	{
		ft_printf("\u250F\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2513\n");
		ft_printf("\u2503   Map trop grande !  \u2503\n");
		ft_printf("\u2517\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u251B\n");
		exit(0);
	}
	if (error == 2)
	{
		ft_printf("\u250F\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2513\n");
		ft_printf("\u2503   Merci de ramasser tous les barils  \u2503\n");
		ft_printf("\u2503       avant de vous téléporter       \u2503\n");
		ft_printf("\u2517\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u251B\n");
	}
}

void	print_error_2(int error)
{
	if (error == 1)
	{
		ft_printf("\u250F\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2513\n");
		ft_printf("\u2503  Assurez-vous d'avoir UN personnage  \u2503\n");
		ft_printf("\u2503            et UNE sortie.            \u2503\n");
		ft_printf("\u2517\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u251B\n");
	}
	if (error == 2)
	{
		ft_printf("\u250F\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2513\n");
		ft_printf("\u2503   Map non rectangulaire !  \u2503\n");
		ft_printf("\u2517\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u251B\n");
	}
	exit(0);
}

void	print_error_3(int error)
{
	if (error == 1)
	{
		ft_printf("\033[38;2;255;165;0m");
		ft_printf("\u250F\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2513\n");
		ft_printf("\u2503  La map n'est pas entouré  \u2503\n");
		ft_printf("\u2503           de murs !        \u2503\n");
		ft_printf("\u2517\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u251B\n");
	}
	if (error == 2)
	{
		ft_printf("\033[38;2;255;165;0m");
		ft_printf("\u250F\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2513\n");
		ft_printf("\u2503   Map trop petite !  \u2503\n");
		ft_printf("\u2517\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u251B\n");
	}
	exit(0);
}

void	print_error_4(int error)
{
	if (error == 1)
	{
		ft_printf("\033[31m");
		ft_printf("\u250F\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2513\n");
		ft_printf("\u2503   Fichier non trouvé !   \u2503\n");
		ft_printf("\u2503    Merci de corriger     \u2503\n");
		ft_printf("\u2503   le lien vers la map.   \u2503\n");
		ft_printf("\u2517\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u251B\n");
	}
	if (error == 2)
	{
		ft_printf("\033[31m");
		ft_printf("\u250F\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2513\n");
		ft_printf("\u2503 Format de map incorrect ! \u2503\n");
		ft_printf("\u2517\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501");
		ft_printf("\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u251B\n");
	}
	exit(0);
}
