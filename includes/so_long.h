/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:16:14 by eunlu             #+#    #+#             */
/*   Updated: 2025/03/21 05:42:34 by emir             ###   ########.fr       */
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
void	ft_error(char *str);

//control.c
t_game	control(t_game game);

#endif