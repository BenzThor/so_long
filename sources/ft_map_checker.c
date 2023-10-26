/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:44:03 by tbenz             #+#    #+#             */
/*   Updated: 2023/10/26 18:04:12 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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

void	ft_check_path_helper(t_data *game, char **map, int x, int y, int d)
{
	if (d == 1)
		y -= 1;
	else if (d == 2)
		y += 1;
	else if (d == 3)
		x -= 1;
	else if (d == 4)
		x += 1;
	if (map[y][x] == 'C')
		game->collectibles++;
	if (map[y][x] == 'E')
		game->exit++;
	ft_check_path(game, map, x, y);
}

void	ft_check_path(t_data *game, char **map_cpy, int x, int y)
{
	char	**map;

	map = map_cpy;
	map[y][x] = 'V';
	if (y > 1 && map[y - 1][x] != '1' && \
		map[y - 1][x] != 'V')
		ft_check_path_helper(game, map, x, y, 1);
	if (y < game->rows - 2 && map[y + 1][x] != '1' && \
		map[y + 1][x] != 'V')
		ft_check_path_helper(game, map, x, y, 2);
	if (x > 1 && map[y][x - 1] != '1' && \
		map[y][x - 1] != 'V')
		ft_check_path_helper(game, map, x, y, 3);
	if (x < game->col - 2 && map[y][x + 1] != '1' && \
			map[y][x + 1] != 'V')
		ft_check_path_helper(game, map, x, y, 4);
}

int	ft_map_checker(t_data *game)
{
	char	**map_cpy;

	map_cpy = ft_copy_map(game);
	if (!map_cpy)
		ft_putstr_fd(MAPCPY_ERR, 2);
	ft_error_code_printer(game, 1);
	ft_check_objects(game);
	ft_check_surroundings(game);
	game->collectibles = 0;
	game->exit = 0;
	ft_check_path(game, map_cpy, game->x,game->y);
	if (game->exit != 1 || game->collectibles < 1)
		game->error_code = -6;
	ft_error_code_printer(game, 3);
	return (game->error_code);
}
