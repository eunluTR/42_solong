/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:39:43 by eunlu             #+#    #+#             */
/*   Updated: 2025/03/22 01:25:19 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void free_map(t_game game)
{
	int	i;

	i = 0;
	while (game.map[i])
	{
		free(game.map[i]);
		i++;
	}
	free(game.map);
}

void	ft_error(t_game game, char *str)
{
	free_map(game);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	exit (0);
}
