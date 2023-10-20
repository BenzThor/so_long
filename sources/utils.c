/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:20:04 by tbenz             #+#    #+#             */
/*   Updated: 2023/10/20 19:15:53 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_code_printer(t_data *game, int n)
{
	if (n == 1 && game->error_code < 0)
	{
		if (game->error_code == -1)
			ft_printf("Error\nThere has been a malloc error!\n");
		if (game->error_code == -2)
			ft_printf("Error\nThe map is not rectangular!\n");
		if (game->error_code == -3)
			ft_printf("Error\nThe file path you provided is not valid!\n");
	}
	if (n == 2)
	{
		if (game->exit != 1)
			ft_printf("Error\nThere is an issue with your exit(s)!\n");
		if (game->collectibles < 1)
			ft_printf("Error\nThere is no collectible!\n");
		if (game->player != 1)
			ft_printf("Error\nThere is an issue with your starting position!\n");
	}
	if (n == 3)
	{
		if (game->error_code == -6)
			ft_printf("Error\nYour map is not solvable!\n");
	}
}
