/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:48:19 by babreton          #+#    #+#             */
/*   Updated: 2023/03/13 15:31:19 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FORMAT "cspdiuxX%"

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int	ft_putchar(int c);
int	thumb(char thumbnail, va_list args);
int	check_args(char next, va_list args);
int	brain(int *i, char now, char next, va_list args);
int	ft_printf(const char *format, ...);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_puthexa(unsigned int nb, char *base);
int	ft_adress(void *ptr);
int	ft_putunbr(unsigned int nb);

#endif //FT_PRINTF_H
