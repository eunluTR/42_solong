/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:16:07 by emir              #+#    #+#             */
/*   Updated: 2025/03/21 19:22:00 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	copy_map(t_game game)
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

static void	check_borders(t_game game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game.column || y >= game.line)
		ft_error(game, "Map is not surrounded by walls!\n");
}



void	flood_fill(char **map, int x, int y)
{

}