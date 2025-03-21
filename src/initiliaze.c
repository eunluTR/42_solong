/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiliaze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:30:41 by emir              #+#    #+#             */
/*   Updated: 2025/03/22 01:35:03 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void initiliaze_game(t_game *game)
{
	game->map = NULL;
	game->column = 0;
	game->line = 0;
	game->move = 0;
	game->x = 0;
	game->y = 0;
	game->e = 0;
	game->c = 0;
	game->player = NULL;
	game->door = NULL;
	game->coin = NULL;
	game->soil = NULL;
	game->wall = NULL;
	game->init = NULL;
	game->win = NULL;
	game->filename = NULL;
}
