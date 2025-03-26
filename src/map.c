/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:35:29 by eunlu             #+#    #+#             */
/*   Updated: 2025/03/26 15:54:31 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_newline(char *line)
{
	int	len;
	int	i;

	len = ft_strlen(line);
	i = 0;
	while (i < len - 1)
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
		{
			ft_putstr_fd("Error: Invalid map! (consecutive newlines)\n", 2);
			free(line);
			exit(1);
		}
		i++;
	}
	if (line[0] == '\n' || len == 0 || line[len - 1] == '\n')
	{
		ft_putstr_fd("Error: Invalid map!\n", 2);
		free(line);
		exit(1);
	}
}

t_game	read_map(t_game game, char **map)
{
	char	*str;
	char	*line;
	int		fd;
	char	*tmp;

	fd = open(map[1], O_RDONLY);
	if (fd < 0)
		exit (1);
	line = ft_strdup("");
	str = get_next_line(fd);
	while (str)
	{
		tmp = line;
		line = ft_strjoin(line, str);
		free(str);
		free(tmp);
		str = get_next_line(fd);
	}
	free (str);
	fd = close(fd);
	is_newline(line);
	game.map = ft_split(line, '\n');
	free (line);
	initialize_player_position(&game);
	return (game);
}
