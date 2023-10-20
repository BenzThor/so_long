/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:10:38 by tbenz             #+#    #+#             */
/*   Updated: 2023/10/20 19:03:29 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../libraries/libft/libft.h"
/*
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_data;
*/
typedef struct s_data
{
	//for image
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
	//for game
	char	*map_file;
	char	**map;
	int		rows;
	int		col;
	int		collectibles;
	int		exit;
	int		player;
	int		x;
	int		y;
	int		error_code;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int		ft_create_map(t_data *game);
int		ft_rows_and_col(int fd, t_data *game);
void	ft_check_objects(t_data *game);
void	ft_check_surroundings(t_data *game);
int		ft_map_checker(t_data *game);
int		ft_create_map(t_data *game);
void	ft_check_path(t_data *game, t_data gmc);
void	ft_check_path_helper(t_data *game, t_data gc, int d);
void	ft_error_code_printer(t_data *game, int n);

#endif
