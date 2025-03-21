/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:16:14 by eunlu             #+#    #+#             */
/*   Updated: 2025/03/22 01:23:28 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

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
t_game read_map(char **map);

//error.c
void	free_map(t_game game);
void	ft_error(t_game game, char *str);

//control.c
t_game	control(t_game game, char *filename);

//flood_fill.c
void	check_extension(t_game game, char *filename);
void	flood_fill(t_game game);

#endif