/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortest_path_copy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:34:12 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/01 18:28:27 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_shortest_path(t_data *game)
{
	t_bfs *lst;
	int		i;

	lst = ft_lstnew_bfs(game);
	i = ft_nav_map(game, &lst);
	return (i);
}

t_bfs	*ft_lstnew_bfs(t_data *game)
{
	t_bfs	*nn;

	nn = (t_bfs *)malloc(sizeof(t_bfs));
	if (nn == NULL)
		return (NULL);
	nn->dist = 0;
	nn->x = game->x;
	nn->y = game->y;
	nn->ptr = NULL;
	return (nn);
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
	return (-1);
}

void ft_list_append(t_bfs **lst, int dist, int x, int y)
{
	t_bfs *node;
	t_bfs	*last;

	last = ft_lstlast_bfs(*lst);
	node = (t_bfs *)malloc(sizeof(t_bfs));
	if (node == NULL)
		return ;
	node->x = x;
	node->y = y;
	node->ptr = NULL;
	node->dist = dist + 1;
	last->ptr = node;
}

void	ft_node_pop(t_bfs **lst)
{
	t_bfs	*temp;

	temp = (*lst)->ptr;
	free(*lst);
	(*lst) = temp;
}
