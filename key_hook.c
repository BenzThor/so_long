/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:16:24 by tbenz             #+#    #+#             */
/*   Updated: 2023/10/23 16:16:02 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *game)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		// ft_player_move(game, game->map.player.y - 1, game->map.player.x, BACK);
	if (keycode == KEY_LEFT || keycode == KEY_A)
		// ft_player_move(game, game->map.player.y, game->map.player.x - 1, LEFT);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		// ft_player_move(game, game->map.player.y, game->map.player.x + 1, RIGHT);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		// ft_player_move(game, game->map.player.y + 1, game->map.player.x, FRONT);
	if (keycode == KEY_Q || keycode == KEY_ESC)
		// ft_close_game(game);
	return (0);
}
