/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:16:24 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/01 12:35:33 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	ft_key_hook(int keycode, t_data *game)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		ft_player_move(game, 1, game->x, game->y - 1);
	if (keycode == KEY_LEFT || keycode == KEY_A)
		ft_player_move(game, 2, game->x - 1, game->y);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		ft_player_move(game, 3, game->x + 1, game->y);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		ft_player_move(game, 4, game->x, game->y + 1);
	if (keycode == KEY_Q || keycode == KEY_ESC)
	{
		ft_close_game(game);
	}
	return (0);
}

void	ft_player_move(t_data *game, int dir, int x, int y)
{
	char	pos;

	game->d = dir;
	pos = game->map[y][x];
	if (pos == 'E' && game->collectibles == 0)
		ft_close_game(game);
	else if (pos == '0' || pos == 'C' || pos == 'E')
	{
		ft_set_game_tile(game, x, y);
		game->map[y][x] = 'P';
		game->x = x;
		game->y = y;
		if (pos == 'C')
			(game->collectibles)--;
		game->movements += 1;
		ft_determine_sprite(game, x, y);
		ft_print_movements(game);
	}
}

void ft_set_game_tile(t_data *game, int x, int y)
{
		if (!game->tile)
			game->tile = '0';
		game->map[game->y][game->x] = game->tile;
		ft_determine_sprite(game, game->x, game->y);
		if (game->map[y][x] == 'E')
			game->tile = 'E';
		else
			game->tile = '0';
}

void	ft_close_game(t_data *game)
{
	ft_free_images(game);
	ft_free(game->map, game->rows);
	mlx_destroy_window(game->mlx, game->wdw);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	free(game->mlx);
	exit (0);
}

void	ft_free_images(t_data *game)
{
	mlx_destroy_image(game->mlx, game->xmp_img.r.a[0].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.r.a[1].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.r.a[2].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.r.a[3].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.floor.xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.exit.xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.collectible.xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.borders.xpm_ptr);
	mlx_loop_end(game->mlx);
}
