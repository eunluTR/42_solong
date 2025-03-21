/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir <emir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:15:13 by eunlu             #+#    #+#             */
/*   Updated: 2025/03/21 19:07:12 by emir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_game	map = {0};

	if (argc == 2)
	{
		map =  read_map(argv);
	}
	if (!map.map[0])
		ft_error(map, "Map file is empty!\n");
	map = control(map);
	return (0);
}
