/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:35:29 by eunlu             #+#    #+#             */
/*   Updated: 2025/03/26 07:56:29 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

t_game read_map(t_game game, char **map)
{
	char	*str;
	char	*line;
	int		fd;
	
	fd = open(map[1], O_RDONLY);
	if (fd < 0)
		exit (0);
	line = ft_strdup("");
	str = get_next_line(fd);
	while (str)
	{
		line = ft_strjoin(line, str);
		free(str);
		str = get_next_line(fd);
	}
	free (str);
	fd = close(fd);
	game.map = ft_split(line, '\n');
	free (line);
	return (game);
}
