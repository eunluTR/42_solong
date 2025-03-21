/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:16:07 by emir              #+#    #+#             */
/*   Updated: 2025/03/22 01:26:45 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**copy_map(t_game game)
{
	int		i;
	char	**copy;

	i = 0;
	copy = (char **)malloc(sizeof(char *) * (game.column + 1));
	if (!copy)
		ft_error(game, "Memory allocation failed!\n");
	while (i < game.column)
	{
		copy[i] = ft_strdup(game.map[i]);
		if (!copy[i])
			ft_error(game, "Memory allocation failed!\n");
		++i;
	}
	copy[i] = NULL;
	return (copy);
}

static void	check_adj(t_game game, int x, int y)
{
	if (game.map[y][x] == '1' || game.map[y][x] == 'X')
		return ;
	else if (game.map[y][x] == 'E')
	{
		game.map[y][x] = 'X';
		return ; 
	}
	game.map[y][x] = 'X';
	check_adj(game, x + 1, y);
	check_adj(game, x - 1, y);
	check_adj(game, x, y + 1);
	check_adj(game, x, y - 1);
}

static void check_collectable(t_game game)
{
	int	i;
	int j;

	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			if (game.map[i][j] == 'E' || game.map[i][j] == 'C')
			{
				ft_free(game.map);
				ft_error(game, "No available path to collectables!\n");
			}
			++j;
		}
		++i;
	}
}

void	check_extension(t_game game, char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(&filename[len - 4], ".ber", 4))
	{
		ft_error(game, "Error: Invalid map extension!\n");
		exit(1);
	}
}

static void	free_maps(char **map) //degistir bunu
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	flood_fill(t_game game)
{
	char **map;

	if (game.x < 0 || game.y < 0)
		ft_error(game, "Cannot find player position!\n");
	map = copy_map(game);
	check_adj(game, game.x, game.y);
	check_collectable(game);
	free_maps(map);
}