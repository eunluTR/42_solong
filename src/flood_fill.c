/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:16:07 by emir              #+#    #+#             */
/*   Updated: 2025/03/26 12:03:40 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/so_long.h"

// static char	copy_map(t_game game)
// {
// 	int 	i;
// 	char	**copy;
	
// 	i = 0;
// 	copy = (char **)malloc(sizeof(char *) * game.column + 1);
// 	if (!copy)
// 		ft_error(game, "Memory Allocation Failed!\n");
// 	while (i < game.column)
// 	{
// 		copy[i] = ft_strdup(game.map[i]);
// 		if (!copy[i])
// 			ft_error(game, "Memory Allocation Failed!\n");
// 		++i;
// 	}
// 	copy[i] = NULL;
// 	return (copy);
// }

// static void	flood_fill(t_game game, char **map, int x, int y)
// {
// 	if (x < 0 || y < 0 || x >= game.column || y >= game.line)
// 		return ;
// 	if (map[x][y] == '1' || map[x][y] == 'X')
// 		return ;
// 	map[x][y] = 'X';
// 	if (map[x][y] == 'E')
// 		return ;
// 	flood_fill(game, map, x + 1, y);
// 	flood_fill(game, map, x - 1, y);
// 	flood_fill(game, map, x, y + 1);
// 	flood_fill(game, map, x, y - 1);
// }

// static void	check_path(t_game game, char **map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == 'E' || map[i][j] != 'C')
// 			{
// 				ft_error(game, "Map is not surrounded by walls!\n");
// 				free (map);
// 			}
// 			++j;
// 		}
// 		++i;
// 	}
// }

// void	flood_fill(t_game game)
// {
// 	char **map;

// 	map = copy_map(game);
// 	check_adj(map, game.x, game.y);
// 	check_collectable(game);
// 	free_map(map);
// }
