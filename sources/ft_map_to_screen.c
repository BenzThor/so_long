/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:36:18 by tbenz             #+#    #+#             */
/*   Updated: 2023/10/26 18:37:49 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	ft_put_sprite(t_data *game, t_image *sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->wdw, sprite, IMG_SIZE * x, \
							IMG_SIZE * y);
}

void	ft_determine_sprite(t_data *game, int x, int y)
{
	char pos;

	pos = game->map[y][x];
	if (pos == '0')
		ft_put_sprite(game, game->xmp_img.floor.xpm_ptr, x, y);
	else if (pos == '1')
		ft_put_sprite(game, game->xmp_img.borders.xpm_ptr, x, y);
	else if (pos == 'C')
		ft_put_sprite(game, game->xmp_img.collectible.xpm_ptr, x, y);
	else if (pos == 'E')
		ft_put_sprite(game, game->xmp_img.exit.xpm_ptr, x, y);
	else if (pos == 'P')
		ft_put_sprite(game, game->xmp_img.right.xpm_ptr, x, y);
}

void	ft_map_to_screen(t_data *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->rows)
	{
		x = -1;
		while(++x < game->col)
			ft_determine_sprite(game, x, y);
	}
	// ft_print_movements(game);
}
