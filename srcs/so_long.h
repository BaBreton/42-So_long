/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:13:45 by babreton          #+#    #+#             */
/*   Updated: 2023/03/23 20:25:32 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>
# include <stdlib.h>
# include "../includes/printf/ft_printf.h"
# include "../includes/mlx/mlx.h"
# include "../includes/mlx/mlx_int.h"

# define MAX_MAP_SIZE 	942
# define LEFT 			65361
# define UP 			65362
# define RIGHT 			65363
# define DOWN 			65364
# define ESCAPE 		65307
# define ENTER			65293
# define DO				65364
# define RI				65363
# define LE				65361
# define Q				113
# define D				100
# define S				115
# define Z				122
# define GROUND			10
# define T_LEFT			20
# define T_RIGHT		21
# define TOP			22
# define B_LEFT			30
# define B_RIGHT		31
# define BOTTOM			32
# define S_LEFT			35
# define S_RIGHT		36
# define CENTRAL		40
# define EXIT			41
# define COLLECTIBLES	42
# define PLAYER			43
# define EXIT_F			44
# define BANNER			45
# define OVER			46
# define DEAD			47
# define T01			50
# define T02			51
# define T03			52
# define T04			53
# define T05			54
# define T06			55
# define T07			56
# define T08			57
# define T11			58
# define T12			59
# define T13			60
# define T14			61
# define T15			62
# define T16			63
# define T17			64
# define T18			65
# define T19			66
# define T20			67
# define L_T			68
# define END			1000

typedef struct s_traps
{
	void	*t01;
	void	*t02;
	void	*t03;
	void	*t04;
	void	*t05;
	void	*t06;
	void	*t07;
	void	*t08;
	void	*t11;
	void	*t12;
	void	*t13;
	void	*t14;
	void	*t15;
	void	*t16;
	void	*t17;
	void	*t18;
	void	*t19;
	void	*t20;
	void	*dead;
}			t_traps;

typedef struct s_tiles
{
	void	*p_up;
	void	*p_down;
	void	*p_right;
	void	*p_left;
	void	*happy;
	void	*t_left;
	void	*t_right;
	void	*top;
	void	*b_left;
	void	*b_right;
	void	*bottom;
	void	*left;
	void	*right;
	void	*central;
	void	*ground;
	void	*exit_e;
	void	*exit_f;
	void	*collec;
	void	*text;
	void	*banner;
	void	*over;
}			t_tiles;

typedef struct s_size
{
	int	size_x;
	int	size_y;
	int	win_x;
	int	win_y;
}		t_size;

typedef struct s_integers
{
	int	move_count;
	int	nb_collectibles;
	int	nb_traps;
	int	identifier;
	int	time;
	int	traps_on;
	int	ingame;
}		t_integers;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	void		*exit_win;
	void		*game_over;
	char		**map;
	int			coord_x;
	int			coord_y;
	t_traps		traps;
	t_integers	ints;
	t_size		size;
	t_tiles		tiles;
}				t_window;

/*-----INITIALIZATION---------------------------------------------------------*/
void	integers_init(t_window *win);
void	window_init(char *path, t_window *win);
void	tiles_init(int i, t_window	*win);
void	tiles_init_2(int i, t_window *win);
void	traps_init(int i, t_window *win);
void	traps_init_2(int i, t_window *win);

/*-----MAP--------------------------------------------------------------------*/
/*--------check-map-format--------*/
void	load_map(char *path, t_window *win);
void	check_map_format(char *path, t_window *win);
void	check_map_lenght(char *buffer, int bytes_read, t_window *win);
void	check_map_wall(char *buffer);
void	check_map_square(char *buffer, t_window *win);
void	check_map_requirements(char *buffer, t_window *win);
void	check_minimal_lenght(t_window *win);
/*--------check-map-format--------*/
/*--------map-memory-allocation---*/
void	map_allocation(t_window *win);
void	tab_init(char *path, t_window *win);
void	get_player_coords(char *path, t_window *win);
void	desallocate(t_window *win);
/*--------map-memory-allocation---*/

/*-----TILES------------------------------------------------------------------*/
void	tiles_board(t_window *i);
void	put_tiles(t_window *win);
void	put_ground(t_window *win);
void	put_traps(t_window *win);
void	put_wall(t_window *win);

/*-----IMAGES-----------------------------------------------------------------*/
void	put_image(t_window *win, int identifier, int x, int y);
void	put_image_2(t_window *win, int identifier, int x, int y);
void	put_image_traps(t_window *win, int identifier, int x, int y);
void	put_image_traps_2(t_window *win, int identifier, int x, int y);

/*-----ERRORS-----------------------------------------------------------------*/
void	check_error(int error);
void	print_error_1(int error);
void	print_error_2(int error);
void	print_error_3(int error);
void	print_error_4(int error);

/*-----TRAPS-ANIMATION--------------------------------------------------------*/
int		anim_traps(t_window *win);
void	random_number(t_window *win);
void	traps_loop_on(t_window *win);
void	traps_loop_off(t_window *win);

/*-----EVENTS-/-MOVING--------------------------------------------------------*/
int		keys(int key, t_window *win);
void	down_event(t_window *win);
void	up_event(t_window *win);
void	right_event(t_window *win);
void	left_event(t_window *win);

/*-----WINDOW-EXIT------------------------------------------------------------*/
void	exit_win(t_window *win);
void	change_exit(t_window *win);
int		exit_key(int key, t_window *win);
int		exit_quit(t_window *win);

/*-----WINDOW-GAME-OVER-------------------------------------------------------*/
void	game_over_win(t_window *win);
int		game_over_key(int key, t_window *win);
int		game_over_quit(t_window *win);

/*-----MISC-------------------------------------------------------------------*/
void	check_trap(int identifier, t_window *win);
void	check_trap_2(int identifier, t_window *win);
void	check_exit(t_window *win);
char	*win_title(char *s1, char *s2);
char	*menu(void);
char	*check_format(char	*answer);
char	*ft_itoa(int n);
int		ft_abs(int n);
int		count_digits(int n);
int		quit(t_window *win);
void	destroy_images(t_window *win);
void	destroy_images_2(t_window *win);

#endif //SO_LONG_H