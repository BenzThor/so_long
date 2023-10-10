/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:45:21 by tbenz             #+#    #+#             */
/*   Updated: 2023/10/10 12:26:31 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*ft_make_map(int argc, char **argv, t_data *game)
{
	if (argc == 2)
	{
		game->map_file = argv[1];
		if (!game->map_file)
			return (NULL);
		ft_create_map(game);
	}
	return (NULL);
}
