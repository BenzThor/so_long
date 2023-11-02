/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:38:05 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/02 13:32:53 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(void)
{
	t_data	game;
	int		i;

	ft_initialize_game(&game);
	game.map_file = "./map/map1.ber";
	ft_create_map(&game);
	ft_map_checker(&game);
	i = 0;
	while (i < game.rows)
	{
		printf("%s\n", game.map[i]);
		i++;
	}
	ft_shortest_path(&game);
	printf("%d", game.sp);
}
