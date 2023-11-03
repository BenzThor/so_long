/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:39:05 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/03 16:12:22 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_enemy(t_data *game)
{
	t_enemy	*temp;
	t_enemy	*temp2;

	temp = game->enemy;
	while (temp)
	{
		temp2 = temp->ptr;
		free (temp);
		temp = temp2;
	}
	game->enemy = NULL;
}

void	ft_check_command_line_arguments(int argc, char **argv, t_data *game)
{
	int	map_parameter_len;

	if (argc > 2)
	{
		ft_putstr_fd(ARGC_ERR1, 1);
		ft_close_game(game);
	}
	if (argc < 2)
	{
		ft_putstr_fd(ARGC_ERR2, 1);
		ft_close_game(game);
	}
	map_parameter_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][map_parameter_len - 4], ".ber", 4))
	{
		ft_putstr_fd(ARGC_ERR3, 1);
		ft_close_game(game);
	}
}

void	ft_check_tiles(t_data *game, char pos, int i, int j)
{
	if (pos == 'E')
		game->exit++;
	else if (pos == 'C')
		game->collectibles++;
	else if (pos == 'P')
	{
		game->player++;
		game->x = j;
		game->y = i;
	}
	else if (pos == 'G')
		game->enemy_num++;
	else if (pos != '1' && pos != '0')
		game->error_code = -7;
}
