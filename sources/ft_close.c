/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:44:42 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/03 13:57:58 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win_loose(t_data *game, int mov_to_end, int movto)
{
	if (movto == 'E')
	{
		if (game->sp == game->movements - mov_to_end + 1)
			ft_putstr_fd(WIN_MESS, 1);
		else
			ft_putstr_fd(LO_MESS, 1);
	}
	ft_close_game(game);
}

int	ft_close_game(t_data *game)
{
	ft_images_to_free(game);
	if (game->map)
		ft_free(game->map, game->rows);
	if (game->mlx)
		mlx_destroy_window(game->mlx, game->wdw);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		mlx_loop_end(game->mlx);
		free(game->mlx);
	}
	exit (0);
	return (0);
}

void	ft_images_to_free(t_data *game)
{
	ft_free_images(game, game->xmp_img.r.a[0].xpm_ptr);
	ft_free_images(game, game->xmp_img.l.a[0].xpm_ptr);
	ft_free_images(game, game->xmp_img.f.a[0].xpm_ptr);
	ft_free_images(game, game->xmp_img.b.a[0].xpm_ptr);
	ft_free_images(game, game->xmp_img.floor.xpm_ptr);
	ft_free_images(game, game->xmp_img.exit.xpm_ptr);
	ft_free_images(game, game->xmp_img.collectible.xpm_ptr);
	ft_free_images(game, game->xmp_img.borders.xpm_ptr);
	if (game->mlx)
		mlx_loop_end(game->mlx);
}

void	ft_free_images(t_data *game, void *xpm_ptr)
{
	if (xpm_ptr)
		mlx_destroy_image(game->mlx, xpm_ptr);
}
