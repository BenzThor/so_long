/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:40:59 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/02 13:54:52 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bfs	*ft_lstnew_bfs(t_data *game)
{
	t_bfs	*nn;

	nn = (t_bfs *)malloc(sizeof(t_bfs));
	if (nn == NULL)
		return (NULL);
	ft_node_init(&nn, game->x, game->y, 0);
	return (nn);
}

void	ft_list_append(t_bfs **lst, int dist, int y, int x)
{
	t_bfs	*node;
	t_bfs	*last;

	last = ft_lstlast_bfs(*lst);
	node = (t_bfs *)malloc(sizeof(t_bfs));
	if (node == NULL)
		return ;
	ft_node_init(&node, x, y, dist + 1);
	last->ptr = node;
}

void	ft_node_pop(t_bfs **lst)
{
	t_bfs	*temp;

	temp = (*lst)->ptr;
	free(*lst);
	(*lst) = temp;
}

void	ft_node_init(t_bfs **node, int x, int y, int dist)
{
	(*node)->x = x;
	(*node)->y = y;
	(*node)->dist = dist;
	(*node)->ptr = NULL;
}

t_bfs	*ft_lstlast_bfs(t_bfs *lst)
{
	while (lst != NULL)
	{
		if (lst->ptr == NULL)
			return (lst);
		lst = lst->ptr;
	}
	return (lst);
}
