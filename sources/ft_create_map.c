/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:00:17 by tbenz             #+#    #+#             */
/*   Updated: 2023/10/09 18:39:46 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_close(char *line, int fd)
{
	free(line);
	close(fd);
}

int	ft_rows_and_columns(int fd, t_data *game)
{
	char	*line;
	int		column_control;

	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_free_close(line, fd);
		return (game->error_code = -1);
	}
	while (line[game->columns] && line[game->columns] != '\n')
		game->columns++;
	while (line)
	{
		column_control = 0;
		while (line[column_control] && line[column_control] != '\n')
			column_control++;
		if (column_control != game->columns)
			return (game->error_code = -2);
		game->rows++;
		free(line);
		line = get_next_line(fd);
	}
	ft_free_close(line, fd);
	return (0);
}

static void	ft_free(char **arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(arr[j++]);
	free (arr);
}

int	ft_fill_map(int fd, t_data *game)
{
	int		i;
	char	*line;

	game->map = (char **)malloc(sizeof(char *) * game->rows);
	if (!game->map)
		return (game->error_code = -1);
	i = 0;
	while (i < game->rows)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free(line);
			close(fd);
			return (game->error_code = -1);
		}
		game->map[i++] = ft_substr(line, 0, game->columns);
		if (!game->map[i - 1])
		{
			ft_free(game->map, i);
			return (game->error_code = -1);
		}
		free(line);
	}
	return (0);
}

int	ft_create_map(t_data *game)
{
	int	fd;

	fd = open(game->map_file, O_RDONLY);
	if (fd < 0)
		return (game->error_code = -3);
	ft_rows_and_columns(fd, game);
	if (game->error_code < 0)
		return (game->error_code);
	fd = open(game->map_file, O_RDONLY);
	if (fd < 0)
		return (game->error_code = -3);
	if (ft_fill_map(fd, game) == -1)
		return (-1);
	return (0);
}
