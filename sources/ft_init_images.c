/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:17:46 by tbenz             #+#    #+#             */
/*   Updated: 2023/10/26 15:32:28 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

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
	game->xmp_img.right = ft_convert_images(game, PR1_XPM);
	game->xmp_img.right2 = ft_convert_images(game, PR2_XPM);
	game->xmp_img.right3 = ft_convert_images(game, PR3_XPM);
	game->xmp_img.right4 = ft_convert_images(game, PR4_XPM);
	game->xmp_img.floor = ft_convert_images(game, FLOOR_XPM);
	game->xmp_img.borders = ft_convert_images(game, BORDERS_XPM);
	game->xmp_img.collectible = ft_convert_images(game, COLL_XPM);
	game->xmp_img.exit = ft_convert_images(game, EXIT_XPM);
	if (!game->xmp_img.right.xpm_ptr || !game->xmp_img.right2.xpm_ptr
		|| !game->xmp_img.right3.xpm_ptr || !game->xmp_img.right4.xpm_ptr
		|| game->xmp_img.floor.xpm_ptr || game->xmp_img.borders.xpm_ptr
		|| game->xmp_img.collectible.xpm_ptr || game->xmp_img.exit.xpm_ptr)
		return (1);
	return (0);
}

t_image	ft_convert_images(t_data *game, char *path)
{
	t_image	img;

	img.xpm_ptr = mlx_xpm_file_to_image(game->mlx, path, &img.x, &img.y);
	ft_putstr_fd(path, 1);
	ft_putchar_fd('\n', 1);
	if (!img.xpm_ptr)
		ft_putstr_fd(CONV_ERR, 2);
	else
		ft_putstr_fd("Success\n", 2);
	return (img);
}

int	ft_init(t_data *game)
{
	if (ft_init_mlx(game) == 1 || ft_init_images(game) == 1)
		return (1);
	return (0);
}
