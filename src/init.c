/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:30:41 by emir              #+#    #+#             */
/*   Updated: 2025/03/26 15:18:51 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *game)
{
	game->map = NULL;
	game->column = 0;
	game->line = 0;
	game->move = 1;
	game->x = 0;
	game->y = 0;
	game->e = 0;
	game->c = 0;
	game->p = 0;
	game->player = NULL;
	game->door = NULL;
	game->coin = NULL;
	game->soil = NULL;
	game->wall = NULL;
	game->init = NULL;
	game->win = NULL;
}

void	init_window(t_game *game)
{
	int	x;

	x = 64;
	game->init = mlx_init();
	if (!game->init)
		ft_error(*game, "MLX initialization failed!\n");
	game->win = mlx_new_window(game->init, game->line * x,
			game->column * x, "Banana Republic");
	if (!game->win)
		ft_error(*game, "Window creation failed!\n");
	game->player = mlx_xpm_file_to_image(game->init,
			"textures/player.xpm", &x, &x);
	game->wall = mlx_xpm_file_to_image(game->init, "textures/wall.xpm", &x, &x);
	game->coin = mlx_xpm_file_to_image(game->init,
			"textures/collectible.xpm", &x, &x);
	game->door = mlx_xpm_file_to_image(game->init,
			"textures/exit.xpm", &x, &x);
	game->soil = mlx_xpm_file_to_image(game->init,
			"textures/floor.xpm", &x, &x);
	if (!game->player || !game->wall
		||!game->coin || !game->door || !game->soil)
	{
		ft_putstr_fd("Error: Texture loading failed!\n", 2);
		close_window(game);
	}
}

void	render_map(t_game g)
{
	int	i;
	int	j;

	i = 0;
	while (g.map[i])
	{
		j = 0;
		while (g.map[i][j])
		{
			if (g.map[i][j] == '1')
				mlx_put_image_to_window(g.init, g.win, g.wall, j * 64, i * 64);
			else if (g.map[i][j] == '0')
				mlx_put_image_to_window(g.init, g.win, g.soil, j * 64, i * 64);
			else if (g.map[i][j] == 'C')
				mlx_put_image_to_window(g.init, g.win, g.coin, j * 64, i * 64);
			else if (g.map[i][j] == 'E')
				mlx_put_image_to_window(g.init, g.win, g.door, j * 64, i * 64);
			else if (g.map[i][j] == 'P')
				mlx_put_image_to_window(g.init,
					g.win, g.player, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	setup_events(t_game *game)
{
	mlx_hook(game->win, KEY_PRESS, KEY_PRESS_MASK, key_event, game);
	mlx_hook(game->win, DESTROY_NOTIFY, NO_MASK, close_window, game);
	mlx_loop(game->init);
}
