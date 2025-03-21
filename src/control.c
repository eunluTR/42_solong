/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:51:42 by eunlu             #+#    #+#             */
/*   Updated: 2025/03/22 01:35:13 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_game	map_size(t_game game)
{
	int	line;
	int column;

	line = 0;
	column = 0;
	while (game.map[0][line])
		line++;
	while (game.map[column])
		column++;
	game.line = line;
	game.column = column;
	return (game);
}

static void	is_rectangle(t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
			j++;
		if (j != game.line)
			ft_error(game, "Map is not a rectangle!\n");
		i++;
	}
}

static void	wall_check(t_game game)
{
	int	i;
	int	j;

	if (game.column < 3 || game.line < 3)
		ft_error(game, "Map is too small!\n");
	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			if (i == 0 || i == game.column || j == 0 || j == game.line - 1)
			{
				if (game.map[i][j] != '1')
					ft_error(game, "Map is not surrounded by walls!\n");
			}
			j++;
		}
		i++;
	}
}

static t_game	letter_check(t_game game)
{
	int	i;
	int	j;
	
	game.c = 0;
	game.e = 0;
	game.p = 0;
	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			if (game.map[i][j] == 'C')
				game.c++;
			else if (game.map[i][j] == 'E')
				game.e++;
			else if (game.map[i][j] == 'P')
				game.p++;
			else if (game.map[i][j] != '0' && game.map[i][j] != '1')
				ft_error(game, "Map contains invalid characters!\n");
			j++;
		}
		i++;
	}
	if (!(game.p == 1 && game.c >= 1 && game.e == 1))
		ft_error(game, "Invalid amount of player, exit, or collectible!\n");
	return (game);
}

t_game	control(t_game game, char *filename)
{
	int	len;

	len = 0;
	if (!game.map[0])
		ft_error(game, "Map file is empty!\n");
	len = ft_strlen(game.map[0]);
	if (len < 4)
		ft_error(game, "Invalid map name!\n");
	check_extension(game, filename);
	game = map_size(game);
	is_rectangle(game);
	wall_check(game);
	game = letter_check(game);
	return (game);
}
