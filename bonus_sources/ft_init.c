/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:17:46 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/03 14:02:52 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_init_mlx(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free(game->mlx);
		ft_putstr_fd(MLX_ERR, 2);
		return (1);
	}
	game->wdw = mlx_new_window(game->mlx, IMG_SIZE * game->col, IMG_SIZE * \
								game->rows, "SO_LONG");
	if (!game->mlx)
	{
		free(game->wdw);
		ft_putstr_fd(WDW_ERR, 2);
		return (1);
	}
	return (0);
}

int	ft_init_images(t_data *game)
{
	ft_init_player(game);
	game->xmp_img.floor = ft_convert_images(game, FLOOR_XPM);
	game->xmp_img.borders = ft_convert_images(game, BORDERS_XPM);
	game->xmp_img.collectible = ft_convert_images(game, COLL_XPM);
	game->xmp_img.exit = ft_convert_images(game, EXIT_XPM);
	game->xmp_img.e.a[0] = ft_convert_images(game, E1_XPM);
	game->xmp_img.e.a[1] = ft_convert_images(game, E2_XPM);
	if (!game->xmp_img.r.a[0].xpm_ptr || !game->xmp_img.r.a[1].xpm_ptr
		|| !game->xmp_img.r.a[2].xpm_ptr || !game->xmp_img.r.a[3].xpm_ptr
		|| !game->xmp_img.l.a[0].xpm_ptr || !game->xmp_img.l.a[1].xpm_ptr
		|| !game->xmp_img.l.a[2].xpm_ptr || !game->xmp_img.l.a[3].xpm_ptr
		|| !game->xmp_img.f.a[0].xpm_ptr || !game->xmp_img.f.a[1].xpm_ptr
		|| !game->xmp_img.f.a[2].xpm_ptr || !game->xmp_img.f.a[3].xpm_ptr
		|| !game->xmp_img.b.a[0].xpm_ptr || !game->xmp_img.b.a[1].xpm_ptr
		|| !game->xmp_img.b.a[2].xpm_ptr || !game->xmp_img.b.a[3].xpm_ptr
		|| !game->xmp_img.floor.xpm_ptr || !game->xmp_img.borders.xpm_ptr
		|| !game->xmp_img.collectible.xpm_ptr || !game->xmp_img.exit.xpm_ptr
		|| !game->xmp_img.e.a[0].xpm_ptr || !game->xmp_img.e.a[1].xpm_ptr)
		return (1);
	return (0);
}

void	ft_init_player(t_data *game)
{
	game->xmp_img.r.a[0] = ft_convert_images(game, PR1_XPM);
	game->xmp_img.r.a[1] = ft_convert_images(game, PR2_XPM);
	game->xmp_img.r.a[2] = ft_convert_images(game, PR3_XPM);
	game->xmp_img.r.a[3] = ft_convert_images(game, PR4_XPM);
	game->xmp_img.l.a[0] = ft_convert_images(game, PL1_XPM);
	game->xmp_img.l.a[1] = ft_convert_images(game, PL2_XPM);
	game->xmp_img.l.a[2] = ft_convert_images(game, PL3_XPM);
	game->xmp_img.l.a[3] = ft_convert_images(game, PL4_XPM);
	game->xmp_img.f.a[0] = ft_convert_images(game, PF1_XPM);
	game->xmp_img.f.a[1] = ft_convert_images(game, PF2_XPM);
	game->xmp_img.f.a[2] = ft_convert_images(game, PF3_XPM);
	game->xmp_img.f.a[3] = ft_convert_images(game, PF4_XPM);
	game->xmp_img.b.a[0] = ft_convert_images(game, PB1_XPM);
	game->xmp_img.b.a[1] = ft_convert_images(game, PB2_XPM);
	game->xmp_img.b.a[2] = ft_convert_images(game, PB3_XPM);
	game->xmp_img.b.a[3] = ft_convert_images(game, PB4_XPM);
}

t_image	ft_convert_images(t_data *game, char *path)
{
	t_image	img;

	img.xpm_ptr = mlx_xpm_file_to_image(game->mlx, path, &img.x, &img.y);
	if (!img.xpm_ptr)
		ft_putstr_fd(CONV_ERR, 2);
	return (img);
}

int	ft_init(t_data *game)
{
	if (ft_init_mlx(game) == 1 || ft_init_images(game) == 1)
		return (1);
	return (0);
}
