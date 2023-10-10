/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:44:03 by tbenz             #+#    #+#             */
/*   Updated: 2023/10/10 13:08:56 by tbenz            ###   ########.fr       */
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
		while (++j < game->columns)
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
		while (++j < game->columns)
		{
			if (((j == 0 || j == game->columns - 1)
					&& (i > 0 && i < game->rows - 1)))
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

void	ft_check(t_data *game)
{
	if (game->map[game->yc][game->xc] == 'C')
		game->collectibles

}

void	ft_check_path(t_data *game)
{
	if (game->y > 1 && game->map[game->y - 1][game->x] != 1)
	{
		game->yc = game->y - 1;
		ft_check(game);
		ft_check_path(game);
	}
	if (game->y < game->rows - 2 && game->map[game->y + 1][game->x] != 1)
	{
		game->yc = game->y + 1;
		ft_check(game);
		ft_check_path(game);
	}
	if (game->x > 1 && game->map[game->y][game->x - 1] == 0)
	{
		game->xc = game->x - 1;
		ft_check(game);
		ft_check_path(game);
	}
	if (game->x < game->columns - 2 && game->map[game->y][game->x + 1] != 1)
	{
		game->xc = game->x + 1;
		ft_check(game);
		ft_check_path(game);
	}
}

int	ft_map_checker(t_data *game)
{
	if (game->error_code < 0)
	{
		if (game->error_code == -1)
			ft_printf("Error\nThere has been a malloc error!");
		if (game->error_code == -2)
			ft_printf("Error\nThe map is not rectangular!");
		if (game->error_code == -3)
			ft_printf("Error\nThe file path you provided is not valid!");
		return (game->error_code);
	}
	ft_check_objects(game);
	if (game->exit != 1)
		ft_printf("Error\nThere is an issue with your exit(s)!");
	if (game->collectibles < 1)
		ft_printf("Error\nThere is no collectible!");
	if (game->player != 1)
		ft_printf("Error\nThere is an issue with your starting position!");
	if (game->exit != 1 || game->collectibles < 1 || game->player != 1)
		game->error_code = -4;
	ft_check_surroundings(game);
	ft_check_path(game);
	return (game->error_code);
}
