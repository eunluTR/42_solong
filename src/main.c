/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:15:13 by eunlu             #+#    #+#             */
/*   Updated: 2025/03/22 17:02:36 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_game	game = {0};

	if (argc == 2)
	{
		game =  read_map(argv);
	}
	if (!game.map[0])
		ft_error(game, "Map file is empty!\n");
	game = control(game, argv[1]);
	init_window(&game);
	load_textures(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1, key_event, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.init);

	return (0);
}
