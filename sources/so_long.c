/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:38:05 by tbenz             #+#    #+#             */
/*   Updated: 2023/10/20 15:10:21 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv)
{
	t_list	game;

	ft_initialize_game(&game);
}
/*
int	main(void)
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;
	int		i;
	int		j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 900, 600, "Hello world");
	img.img = mlx_new_image(mlx, 900, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.endian);
	i = 0;
	while (i < 100)
	{
		j = 0;
		while (j <= i / 2)
			my_mlx_pixel_put(&img, 250 + i, 250 + j++, 0xFF0000);
		while (j > 50 && j < 100)
			my_mlx_pixel_put(&img, 250 + i, 250 - j++, 0xFF0000);
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, 2, 1L<<0, )
	mlx_loop(mlx);
} */
