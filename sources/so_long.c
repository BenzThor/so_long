/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:38:05 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/01 19:52:21 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(void)
{
	t_data	game;
	int		check;
	int		i;

	i = 0;
	ft_initialize_game(&game);
	game.map_file = "./map/map.ber";
	printf("%s\n", game.map_file);
	check = ft_create_map(&game);
	printf("size of map: %lu\n", sizeof(game.map));
	printf("col: %d\t rows: %d\t check: %d\n", game.col, game.rows, check);
	ft_map_checker(&game);
	i = 0;
	while (i < game.rows)
	{
		printf("%s\n", game.map[i]);
		i++;
	}
	printf("%d", game.error_code);
	ft_init(&game);
	ft_map_to_screen(&game);
	mlx_hook(game.wdw, 2, 1L << 0, ft_key_hook, &game);
	mlx_hook(game.wdw, 17, 0, ft_close_game, &game);
	mlx_loop_hook(game.mlx, ft_animate_player, &game);
	mlx_loop(game.mlx);
}
