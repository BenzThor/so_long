/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:20:04 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/03 14:03:58 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

char	**ft_copy_map(t_data *game)
{
	int		i;
	char	**map;

	map = (char **)malloc(sizeof(char *) * game->rows);
	if (!map)
		return (NULL);
	i = -1;
	while (++i < game->rows)
	{
		map[i] = ft_substr(game->map[i], 0, game->col);
		if (!map[i])
		{
			ft_free(map, i);
			return (NULL);
		}
	}
	return (map);
}

void	ft_initialize_game(t_data *game)
{
	ft_bzero(game, sizeof(t_data));
}

void	ft_put_sprite(t_data *game, t_image *sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->wdw, sprite, IMG_SIZE * x, \
							IMG_SIZE * y);
}

void	ft_create_new_enemy(t_data *game, int x, int y)
{
	t_enemy	*enemy;
	t_enemy	*temp;

	enemy = malloc(sizeof(t_enemy));
	ft_memset(enemy, 0, sizeof(t_enemy));
	if (!enemy)
		return ;
	enemy->x = x;
	enemy->y = y;
	enemy->ptr = NULL;
	if (game->enemy != NULL)
	{
		temp = game->enemy;
		while (temp->ptr)
			temp = temp->ptr;
		temp->ptr = enemy;
	}
	else
		game->enemy = enemy;
}
