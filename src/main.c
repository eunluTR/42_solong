/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:15:13 by eunlu             #+#    #+#             */
/*   Updated: 2025/03/26 10:12:48 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_game	game;

	check_argc(argc);
	check_extension(argv[1]);
	init_game(&game);
	game =  read_map(game, argv);
	game = control(game);
	init_window(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1, key_event, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.init);
	return (0);
}
