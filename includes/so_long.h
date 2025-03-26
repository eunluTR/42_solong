/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:16:14 by eunlu             #+#    #+#             */
/*   Updated: 2025/03/26 14:54:50 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define NO_MASK 0
#define KEY_PRESS_MASK 1
#define KEY_PRESS 2
#define DESTROY_NOTIFY 17

#define ESC 65307
#define W 119
#define A 97
#define S 115
#define D 100
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"
#include "../minilibx-linux/mlx.h"

typedef struct s_game
{
	char	**map;
	int		column;
	int		line;
	int		move;
	int		x;
	int		y;
	int		e;
	int		p;
	int		c;
	void	*player;
	void	*door;
	void	*coin;
	void	*soil;
	void	*wall;
	void	*init;
	void	*win;
}			t_game;

//map.c
t_game read_map(t_game game, char **map);

//error.c
void	free_map(char **map);
void	ft_error(t_game game, char *str);

//control.c
t_game	control(t_game game);

//flood_fill.c
void	check_extension(char *filename);
void	check_path(t_game game);

//init.c
void	init_game(t_game *game);
void	init_window(t_game *game);
void	render_map(t_game *game);
void	setup_events(t_game *game);

//key_hook.c
void initialize_player_position(t_game *game);
int	key_event(int keycode, t_game *game);
int close_window(t_game *game);

//check.c
t_game	check_empty_map(t_game game);
void	check_rectangle(t_game game);
void	check_walls(t_game game);
t_game	check_letters(t_game game);
void	check_argc(int argc);

#endif