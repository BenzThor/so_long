/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:38:05 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/03 15:52:31 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_data	game;

	ft_initialize_game(&game);
	ft_check_command_line_arguments(argc, argv, &game);
	game.map_file = argv[1];
	if (ft_create_map(&game) < 0)
	{
		ft_error_code_printer(&game, 1);
		ft_close_game(&game);
	}
	if (ft_map_checker(&game) < 0)
		ft_close_game(&game);
	if (ft_init(&game))
		ft_close_game(&game);
	ft_map_to_screen(&game);
	mlx_hook(game.wdw, 2, 1L << 0, ft_key_hook, &game);
	mlx_hook(game.wdw, 17, 0, ft_close_game, &game);
	mlx_loop_hook(game.mlx, ft_animation, &game);
	mlx_loop(game.mlx);
}
