/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:16:24 by tbenz             #+#    #+#             */
/*   Updated: 2023/10/26 19:27:37 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *game)
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
	char	pos;

	pos = game->map[y][x];
	if (pos == 'E' && game->collectibles == 0)
		ft_close_game(game);
	else if (pos == '0' || pos == 'C' || pos = 'E')
	{
		game->tile = pos;
		if (!game->tile)
			game->map[game->y][game->x] = '0';
		else
			game->map[game->y][game->x];
		pos = 'P';
		if (pos = 'C')
			(game->collectibles)--;
		(game->movements)++;
		ft_map_to_screen(game);
	}
}
