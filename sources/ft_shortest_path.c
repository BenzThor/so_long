/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortest_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:34:12 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/02 13:52:02 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_shortest_path(t_data *game)
{
	t_bfs	*lst;

	lst = ft_lstnew_bfs(game);
	ft_nav_map(game, &lst);
	while (lst)
		ft_node_pop(&lst);
	free(lst);
}

void	ft_nav_map(t_data *game, t_bfs **lst)
{
	while (*lst && game->sp < 1)
	{
		if (ft_corrval(game, lst, (*lst)->x + 1, (*lst)->y) && game->sp < 1)
			ft_list_append(lst, (*lst)->dist, (*lst)->y, (*lst)->x + 1);
		if (ft_corrval(game, lst, (*lst)->x - 1, (*lst)->y) && game->sp < 1)
			ft_list_append(lst, (*lst)->dist, (*lst)->y, (*lst)->x - 1);
		if (ft_corrval(game, lst, (*lst)->x, (*lst)->y + 1) && game->sp < 1)
			ft_list_append(lst, (*lst)->dist, (*lst)->y + 1, (*lst)->x);
		if (ft_corrval(game, lst, (*lst)->x, (*lst)->y - 1) && game->sp < 1)
			ft_list_append(lst, (*lst)->dist, (*lst)->y - 1, (*lst)->x);
		game->map[(*lst)->y][(*lst)->x] = ' ';
		ft_node_pop(lst);
	}
}

int	ft_corrval(t_data *game, t_bfs **lst, int x, int y)
{
	char	c;
	t_bfs	*temp;

	c = game->map[y][x];
	if (c == 'E')
	{
		game->sp = (*lst)->dist + 1;
		return (0);
	}
	if (c == '1' || c == ' ' || c == 'G')
		return (0);
	temp = *lst;
	while (*lst)
	{
		if ((*lst)->x == x && (*lst)->y == y)
		{
			*lst = temp;
			return (0);
		}
		*lst = (*lst)->ptr;
	}
	*lst = temp;
	return (1);
}
