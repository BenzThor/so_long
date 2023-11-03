/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:36:18 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/03 14:35:51 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_determine_sprite(t_data *game, int x, int y)
{
	char	pos;

	pos = game->map[y][x];
	if (pos == '0' || pos == 'X')
		ft_put_sprite(game, game->xmp_img.floor.xpm_ptr, x, y);
	else if (pos == '1')
		ft_put_sprite(game, game->xmp_img.borders.xpm_ptr, x, y);
	else if (pos == 'C')
		ft_put_sprite(game, game->xmp_img.collectible.xpm_ptr, x, y);
	else if (pos == 'E')
		ft_put_sprite(game, game->xmp_img.exit.xpm_ptr, x, y);
	else if (pos == 'P')
		ft_put_player(game, x, y);
}

void	ft_put_player(t_data *game, int x, int y)
{
	if (!game->d)
		game->d = 4;
	if (game->d == 1)
		ft_put_sprite(game, game->xmp_img.b.a[0].xpm_ptr, x, y);
	else if (game->d == 2)
		ft_put_sprite(game, game->xmp_img.l.a[0].xpm_ptr, x, y);
	else if (game->d == 3)
		ft_put_sprite(game, game->xmp_img.r.a[0].xpm_ptr, x, y);
	else if (game->d == 4)
		ft_put_sprite(game, game->xmp_img.f.a[0].xpm_ptr, x, y);
}

void	ft_print_movements(t_data *game)
{
	char	*mov;
	char	*movnew;

	mov = ft_itoa(game->movements);
	movnew = ft_strjoin(mov, "\n");
	ft_putstr_fd(movnew, 1);
	free (mov);
	free(movnew);
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
