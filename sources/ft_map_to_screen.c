/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:36:18 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/01 12:49:22 by tbenz            ###   ########.fr       */
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
	char	pos;
	static int fps = 0;

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
		ft_put_player(game, x, y, fps);
	fps++;
	if (fps == 800)
		fps = 0;
}

void	ft_put_player(t_data *game, int x, int y, int fps)
{
	if (!game->d)
		game->d = 4;
	if (game->d == 1)
		ft_put_sprite(game, game->xmp_img.b.a[fps / 200].xpm_ptr, x, y);
	else if (game->d == 2)
		ft_put_sprite(game, game->xmp_img.l.a[fps / 200].xpm_ptr, x, y);
	else if (game->d == 3)
		ft_put_sprite(game, game->xmp_img.r.a[fps / 200].xpm_ptr, x, y);
	else if (game->d == 4)
		ft_put_sprite(game, game->xmp_img.f.a[fps / 200].xpm_ptr, x, y);
}

void ft_print_movements(t_data *game)
{
	char	*mov;
	char	*print;
	int		x;
	int		y;
	int		x_limit;

	x = .027 * (IMG_SIZE * game->col);
	x_limit = 100;
	if (game->movements > 100)
		x_limit = 105;
	while (x++ < x_limit)
	{
		y = .02 * (IMG_SIZE * game->rows);
		while (y++ < 26)
			mlx_pixel_put(game->mlx, game->wdw, x, y, 000000);
	}
	mov = ft_itoa(game->movements);
	print = ft_strjoin("Movements: ", mov);
	mlx_string_put(game->mlx, game->wdw, .05 * (IMG_SIZE * game->col), \
					.08 * (IMG_SIZE * game->rows), 0xFF0000, print);
	free(mov);
	free (print);
}

void	ft_map_to_screen(t_data *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->rows)
	{
		x = -1;
		while (++x < game->col)
			ft_determine_sprite(game, x, y);
	}
	ft_print_movements(game);
}
