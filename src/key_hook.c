/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:00:12 by emir              #+#    #+#             */
/*   Updated: 2025/03/26 14:55:29 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_count(int move)
{
	ft_putnbr_fd(move, 1);
	write(1, "\n", 1);
}

void	initialize_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->x = j;
				game->y = i;
				return ;
			}
			++j;
		}
		++i;
	}
	ft_error(*game, "Error: no player!\n");
}

static void	update_player_position(t_game *game, int dx, int dy)
{
	if (game->map[game->y + dy][game->x + dx] != '1')
	{
		if (game->map[game->y + dy][game->x + dx] == 'C')
			game->c--;
		if (game->map[game->y + dy][game->x + dx] == 'E' && game->c == 0)
		{
			move_count(game->move);
			ft_putstr_fd("Congratulations! You have completed the game with ",
				1);
			ft_putnbr_fd(game->move, 1);
			ft_putstr_fd(" moves!\n", 1);
			game->move++;
			close_window(game);
			return ;
		}
		else if (game->map[game->y + dy][game->x + dx] == 'E' && game->c > 0)
			return ;
		move_count(game->move);
		game->move++;
		game->map[game->y][game->x] = '0';
		game->map[game->y + dy][game->x + dx] = 'P';
		game->y += dy;
		game->x += dx;
		render_map(game);
	}
}

int	key_event(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_window(game);
	else if (keycode == W || keycode == UP)
		update_player_position(game, 0, -1);
	else if (keycode == S || keycode == DOWN)
		update_player_position(game, 0, 1);
	else if (keycode == A || keycode == LEFT)
		update_player_position(game, -1, 0);
	else if (keycode == D || keycode == RIGHT)
		update_player_position(game, 1, 0);
	return (0);
}

void	close_window(t_game *game)
{
	if (game->player)
		mlx_destroy_image(game->init, game->player);
	if (game->wall)
		mlx_destroy_image(game->init, game->wall);
	if (game->coin)
		mlx_destroy_image(game->init, game->coin);
	if (game->door)
		mlx_destroy_image(game->init, game->door);
	if (game->soil)
		mlx_destroy_image(game->init, game->soil);
	if (game->win)
		mlx_destroy_window(game->init, game->win);
	if (game->init)
	{
		mlx_destroy_display(game->init);
		free(game->init);
	}
	free_map(game->map);
	exit(0);
}
