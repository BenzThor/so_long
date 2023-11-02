/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:39:05 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/02 18:50:28 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
