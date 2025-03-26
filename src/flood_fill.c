/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:16:07 by emir              #+#    #+#             */
/*   Updated: 2025/03/26 08:26:34 by eunlu            ###   ########.fr       */
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

void	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(&filename[len - 4], ".ber", 4))
	{
		ft_putstr_fd("Error: Invalid file extension!\n", 2);
		exit (1);
	}
}

void	flood_fill(t_game game)
{
	char **map;

	if (game.x < 0 || game.y < 0)
		ft_error(game, "Cannot find player position!\n");
	map = copy_map(game);
	check_adj(game, game.x, game.y);
	check_collectable(game);
	free_map(map);
}