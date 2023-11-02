/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:22:42 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/02 18:10:54 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_animation(t_data *game)
{
	int	frame_ival;
	frame_ival = ft_define_frame_ival(game);
	ft_animate_player(game, frame_ival);
	ft_animate_enemy(game, frame_ival);
	return (0);
}

void	ft_animate_player(t_data *game, int frame_ival)
{
	if (!game->d)
		game->d = 4;
	if (game->d == 1)
		ft_put_sprite(game, game->xmp_img.b.a[game->curr_frame].xpm_ptr, \
					game->x, game->y);
	else if (game->d == 2)
		ft_put_sprite(game, game->xmp_img.l.a[game->curr_frame].xpm_ptr, \
					game->x, game->y);
	else if (game->d == 3)
		ft_put_sprite(game, game->xmp_img.r.a[game->curr_frame].xpm_ptr, \
					game->x, game->y);
	else if (game->d == 4)
		ft_put_sprite(game, game->xmp_img.f.a[game->curr_frame].xpm_ptr, \
					game->x, game->y);
	game->curr_frame = (game->curr_frame + 1) % FRAME_NUM;
	usleep(frame_ival);
}

void	ft_animate_enemy(t_data *game, int frame_ival)
{
	t_enemy *temp;

	temp = game->enemy;
	while (game->enemy)
	{
		ft_put_sprite(game, game->xmp_img.e.a[game->enemy->frame].xpm_ptr, \
					game->enemy->x, game->enemy->y);
		game->enemy->frame = (game->enemy->frame + 1) % FRAME_ENEM;
		usleep(frame_ival);
		game->enemy = game->enemy->ptr;
	}
	game->enemy = temp;
}

int	ft_define_frame_ival(t_data *game)
{
	int	frame_ival;

	if (!game->enemy_num)
		frame_ival = FRAME_INTERVAL;
	else
		frame_ival = FRAME_INTERVAL / game->enemy_num;
	return (frame_ival);
}
