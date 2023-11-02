/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:20:04 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/02 13:49:33 by tbenz            ###   ########.fr       */
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

int	ft_animate_player(t_data *game)
{
	if (!game->d)
		game->d = 4;
	if (game->d == 1)
		ft_put_sprite(game, game->xmp_img.b.a[game->curr_frame].xpm_ptr, \
					game->x, game->y);
	else if (game->d == 2)
		ft_put_sprite(game, game->xmp_img.l.a[game->curr_frame].xpm_ptr, \
					game->x, game->y);
	else if (game->d == 3)
		ft_put_sprite(game, game->xmp_img.r.a[game->curr_frame].xpm_ptr, \
					game->x, game->y);
	else if (game->d == 4)
		ft_put_sprite(game, game->xmp_img.f.a[game->curr_frame].xpm_ptr, \
					game->x, game->y);
	game->curr_frame = (game->curr_frame + 1) % 4;
	usleep(FRAME_INTERVAL);
	return (0);
}
