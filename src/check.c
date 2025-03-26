/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:00:41 by eunlu             #+#    #+#             */
/*   Updated: 2025/03/26 09:32:37 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	check_empty_map(t_game game)
{
	if (!game.map[0])
		ft_error(game, "Map file is empty!\n");
	return (game);
}

void	check_rectangle(t_game game)
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

void	check_walls(t_game game)
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

t_game	check_letters(t_game game)
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
void	check_argc(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error: Invalid number of arguments!\n", 2);
		exit (1);
	}
}
