/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:39:43 by eunlu             #+#    #+#             */
/*   Updated: 2025/03/22 16:18:23 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	ft_error(t_game game, char *str)
{
	free_map(game.map);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	exit (0);
}
