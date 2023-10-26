/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:16:44 by tbenz             #+#    #+#             */
/*   Updated: 2023/10/26 17:18:10 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

void	ft_initialize_game(t_data *game)
{
	ft_bzero(game, sizeof(t_data));
}

int	main(void)
{
	t_data	game;
	int		check;
	int		i;

	i = 0;
	ft_initialize_game(&game);
	game.map_file = "../map/map.txt";
	printf("%s\n", game.map_file);
	check = ft_create_map(&game);
	printf("size of map: %lu\n", sizeof(game.map));
	printf("col: %d\t rows: %d\t check: %d\n", game.col, game.rows, check);
	while (i < game.rows)
	{
		printf("%s\n", game.map[i]);
		i++;
	}
	ft_map_checker(&game);
	i = 0;
	while (i < game.rows)
	{
		printf("%s\n", game.map[i]);
		i++;
	}
	printf("%d", game.error_code);
}
