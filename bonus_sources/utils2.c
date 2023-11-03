/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:39:05 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/03 15:03:29 by tbenz            ###   ########.fr       */
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
