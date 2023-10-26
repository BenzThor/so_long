/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:44:03 by tbenz             #+#    #+#             */
/*   Updated: 2023/10/25 14:16:21 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_objects(t_data *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->rows)
	{
		j = -1;
		while (++j < game->col)
		{
			if (game->map[i][j] == 'E')
				game->exit++;
			if (game->map[i][j] == 'C')
				game->collectibles++;
			if (game->map[i][j] == 'P')
			{
				game->player++;
				game->x = j;
				game->y = i;
			}
		}
	}
	if (game->exit != 1 || game->collectibles < 1 || game->player != 1)
		game->error_code = -4;
	ft_error_code_printer(game, 2);
}

void	ft_check_surroundings(t_data *game)
{
	int	i;
	int	j;
	int	check;

	i = -1;
	while (++i < game->rows)
	{
		j = -1;
		while (++j < game->col)
		{
			if (((j == 0 || j == game->col - 1)
					&& (i > 0 && i < game->rows - 2)))
				check = 1;
			if (i == 0 || i == game->rows - 1 || check == 1)
			{
				if (game->map[i][j] != '1')
				{
					ft_printf("Error\nThere is an issue with the borders!");
					game->error_code = -5;
					return ;
				}
			}
			check = 0;
		}
	}
}

void	ft_check_path_helper(t_data *game, t_data gc, int d)
{
	if (d == 1)
		gc.y -= 1;
	else if (d == 2)
		gc.y += 1;
	else if (d == 3)
		gc.x -= 1;
	else if (d == 4)
		gc.x += 1;
	if (gc.map[gc.y][gc.x] == 'C')
		game->collectibles++;
	if (gc.map[gc.y][gc.x] == 'E')
		game->exit++;
	ft_check_path(game, gc);
}

void	ft_check_path(t_data *game, t_data gmc)
{
	t_data	gc;

	gc = gmc;
	gc.map[gc.y][gc.x] = 'V';
	if (gc.y > 1 && gc.map[gc.y - 1][gc.x] != '1' && \
		gc.map[gc.y - 1][gc.x] != 'V')
		ft_check_path_helper(game, gc, 1);
	if (gc.y < gc.rows - 2 && gc.map[gc.y + 1][gc.x] != '1' && \
		gc.map[gc.y + 1][gc.x] != 'V')
		ft_check_path_helper(game, gc, 2);
	if (gc.x > 1 && gc.map[gc.y][gc.x - 1] != '1' && \
		gc.map[gc.y][gc.x - 1] != 'V')
		ft_check_path_helper(game, gc, 3);
	if (gc.x < gc.col - 2 && gc.map[gc.y][gc.x + 1] != '1' && \
			gc.map[gc.y][gc.x + 1] != 'V')
		ft_check_path_helper(game, gc, 4);
}

int	ft_map_checker(t_data *game)
{
	ft_error_code_printer(game, 1);
	ft_check_objects(game);
	ft_check_surroundings(game);
	game->collectibles = 0;
	game->exit = 0;
	ft_check_path(game, *game);
	if (game->exit != 1 || game->collectibles < 1)
		game->error_code = -6;
	ft_error_code_printer(game, 3);
	return (game->error_code);
}
