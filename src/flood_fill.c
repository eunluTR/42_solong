/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:16:07 by emir              #+#    #+#             */
/*   Updated: 2025/03/26 14:33:05 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**copy_map(t_game game)
{
	int		i;
	char	**copy;

	copy = malloc(sizeof(char *) * (game.column + 1));
	if (!copy)
		ft_error(game, "Malloc Error\n");
	i = 0;
	while (i < game.column)
	{
		copy[i] = ft_strdup(game.map[i]);
		if (!copy[i])
			ft_error(game, "Malloc Error\n");
		++i;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	else if (map[y][x] == 'E')
	{
		map[y][x] = 'X';
		return ;
	}
	map[y][x] = 'X';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static void	check_valid(t_game game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
			{
				free_map(map);
				ft_error(game, "No valid path to collectibles or exit!\n");
			}
			j++;
		}
		i++;
	}
}

void	check_path(t_game game)
{
	char	**map;

	if (game.x < 0 || game.y < 0)
		ft_error(game, "Player position can not find!\n");
	map = copy_map(game);
	flood_fill(map, game.x, game.y);
	check_valid(game, map);
	free_map(map);
}
