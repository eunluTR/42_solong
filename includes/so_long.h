/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:16:14 by eunlu             #+#    #+#             */
/*   Updated: 2025/03/26 08:25:12 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	char	*filename;
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
void	flood_fill(t_game game);

//init.c
void	initiliaze_game(t_game *game);
void	init_window(t_game *game);
void	load_textures(t_game *game);
void	render_map(t_game *game);

//key_hook.c
void initialize_player_position(t_game *game);
int	key_event(int keycode, t_game *game);
int close_window(t_game *game);

#endif