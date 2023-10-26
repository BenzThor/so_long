/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:20:04 by tbenz             #+#    #+#             */
/*   Updated: 2023/10/25 17:49:54 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_code_printer(t_data *game, int n)
{
	if (n == 1 && game->error_code < 0)
	{
		if (game->error_code == -1)
			ft_putstr_fd(MALL_ERR, 2);
		if (game->error_code == -2)
			ft_putstr_fd(MAP_ERR, 2);
		if (game->error_code == -3)
			ft_putstr_fd(FILE_ERR, 2);
	}
	if (n == 2)
	{
		if (game->exit != 1)
			ft_putstr_fd(EXIT_ERR, 2);
		if (game->collectibles < 1)
			ft_putstr_fd(COLL_ERR, 2);
		if (game->player != 1)
			ft_putstr_fd(ST_POS_ERR, 2);
	}
	if (n == 3)
	{
		if (game->error_code == -6)
			ft_putstr_fd(MAP_ERR2, 2);
	}
}
