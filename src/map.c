/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:35:29 by eunlu             #+#    #+#             */
/*   Updated: 2025/03/22 01:20:37 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

t_game read_map(char **map)
{
	t_game	maps;
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
	maps.map = ft_split(line, '\n');
	free (line);
	return (maps);
}
