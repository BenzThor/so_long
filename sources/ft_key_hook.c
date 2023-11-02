/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:16:24 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/02 19:46:43 by tbenz            ###   ########.fr       */
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
		ft_close_game(game);
	return (0);
}

void	ft_player_move(t_data *game, int dir, int x, int y)
{
	char			movto;
	static int		mov_to_end;

	game->d = dir;
	movto = game->map[y][x];
	if ((movto == 'E' && game->collectibles == 0) || movto == 'G')
		ft_win_loose(game, mov_to_end, movto);
	if (movto != '1')
	{
		ft_set_tiles_stats(game, x, y);
		ft_put_player(game, x, y);
		ft_print_movements(game);
	}
	if (movto == 'C' && game->collectibles == 0)
	{
		ft_shortest_path(game);
		mov_to_end = game->movements;
	}
}

void	ft_set_tiles_stats(t_data *game, int x, int y)
{
	if (game->map[y][x] == 'C')
		(game->collectibles)--;
	if (!game->tile || game->tile == 'X')
		game->tile = '0';
	game->map[game->y][game->x] = game->tile;
	ft_determine_sprite(game, game->x, game->y);
	if (game->map[y][x] == 'E')
		game->tile = 'E';
	else
		game->tile = '0';
	game->map[y][x] = 'P';
	game->x = x;
	game->y = y;
	game->movements += 1;
}

int	ft_close_game(t_data *game)
{
	if (game->enemy_num > 0)
		ft_free_enemy(game);
	ft_free_images(game);
	ft_free(game->map, game->rows);
	mlx_destroy_window(game->mlx, game->wdw);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	free(game->mlx);
	exit (0);
	return (0);
}

void	ft_free_images(t_data *game)
{
	mlx_destroy_image(game->mlx, game->xmp_img.r.a[0].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.r.a[1].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.r.a[2].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.r.a[3].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.l.a[0].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.l.a[1].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.l.a[2].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.l.a[3].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.f.a[0].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.f.a[1].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.f.a[2].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.f.a[3].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.b.a[0].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.b.a[1].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.b.a[2].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.b.a[3].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.e.a[0].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.e.a[1].xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.floor.xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.exit.xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.collectible.xpm_ptr);
	mlx_destroy_image(game->mlx, game->xmp_img.borders.xpm_ptr);
	mlx_loop_end(game->mlx);
}
