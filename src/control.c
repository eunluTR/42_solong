/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:51:42 by eunlu             #+#    #+#             */
/*   Updated: 2025/03/26 12:22:13 by eunlu            ###   ########.fr       */
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

t_game	control(t_game game)
{
	game = check_empty_map(game);
	game = map_size(game);
	check_rectangle(game);
	check_walls(game);
	game = check_letters(game);
	check_path(game);
	return (game);
}
