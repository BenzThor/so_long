/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortest_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:34:12 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/01 17:17:44 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_shortest_path(t_data *game)
{
	t_bfs *lst;

	
	lst = NULL;
	lst->dist = 0;
	lst->ptr = NULL;
	lst->x = game->x;
	lst->y = game->y;
	return (ft_nav_map(game, &lst));
}

int ft_nav_map(t_data *game, t_bfs **lst)
{
	while (lst)
	{
		if (game->map[(*lst)->y][(*lst)->x] == 'E')
			return ((*lst)->dist);
		if (game->map[(*lst)->y][(*lst)->x + 1] != '1')
			ft_list_append(lst, (*lst)->dist,(*lst)->y, (*lst)->x + 1);
		if (game->map[(*lst)->y][(*lst)->x - 1] != '1')
			ft_list_append(lst, (*lst)->dist, (*lst)->y, (*lst)->x - 1);
		if (game->map[(*lst)->y +  1][(*lst)->x] != '1')
			ft_list_append(lst, (*lst)->dist, (*lst)->y + 1, (*lst)->x);
		if (game->map[(*lst)->y - 1][(*lst)->x] != '1')
			ft_list_append(lst, (*lst)->dist, (*lst)->y - 1, (*lst)->x);
		game->map[(*lst)->y][(*lst)->x] = ' ';
		ft_node_pop(lst);
	}
}

void ft_list_append(t_bfs **lst, int dist, int x, int y)
{
	t_bfs *node;
	t_bfs *temp;

	temp = (*lst)->ptr;
	node->x = x;
	node->y = y;
	node->dist = dist + 1;
	while ((*lst)->ptr)
		lst = (*lst)->ptr;
	(*lst)->ptr = node;
}

void	ft_node_pop(t_bfs **lst)
{
	t_bfs	*temp;

	temp = (*lst)->ptr;
	free(*lst);
	lst = temp;
}
