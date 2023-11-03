/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:24:07 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/03 15:46:40 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	else if (pos != '1' && pos != '0')
		game->error_code = -7;
}
