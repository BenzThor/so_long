/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:10:38 by tbenz             #+#    #+#             */
/*   Updated: 2023/10/31 17:36:19 by tbenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* 	include libraries */
# include <mlx.h>
# include "../libraries/libft/libft.h"

/* 	Error Codes */
# define MALL_ERR	"Error\nThere has been a malloc error!\n"
# define MAP_ERR	"Error\nThe map is not rectangular!\n"
# define FILE_ERR	"Error\nThe file path you provided is not valid!\n"
# define MAPCPY_ERR	"Error\nThere has been an error while copying the map\n"
# define EXIT_ERR	"Error\nThere is an issue with your exit(s)!\n"
# define COLL_ERR	"Error\nThere is no collectible!\n"
# define ST_POS_ERR	"Error\nThere is an issue with your starting position!\n"
# define MAP_ERR2	"Error\nYour map is not solvable!\n"
# define CONV_ERR	"Error\nThere has been an error converting an image!\n"
# define MLX_ERR	"Error\nThere has been an issue assigning the mlx ptr\n"
# define WDW_ERR	"Error\nThere has been an issue assigning the window ptr\n"

/* 	Image Definition */
# define IMG_SIZE		32

/* 	key definitions */
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

# define KEY_UP  		65362
# define KEY_LEFT  		65361
# define KEY_RIGHT 		65363
# define KEY_DOWN  		65364

# define KEY_Q			113
# define KEY_ESC  		65307

/* 	sprite paths */
# define PR1_XPM		"sprites/character/right1.xpm"
# define PR2_XPM		"sprites/character/right2.xpm"
# define PR3_XPM		"sprites/character/right3.xpm"
# define PR4_XPM		"sprites/character/right4.xpm"

# define PL1_XPM		"sprites/character/left1.xpm"
# define PL2_XPM		"sprites/character/left2.xpm"
# define PL3_XPM		"sprites/character/left3.xpm"
# define PL4_XPM		"sprites/character/left4.xpm"

# define PF1_XPM		"sprites/character/front1.xpm"
# define PF2_XPM		"sprites/character/front2.xpm"
# define PF3_XPM		"sprites/character/front3.xpm"
# define PF4_XPM		"sprites/character/front4.xpm"

# define PB1_XPM		"sprites/character/back1.xpm"
# define PB2_XPM		"sprites/character/back2.xpm"
# define PB3_XPM		"sprites/character/back3.xpm"
# define PB4_XPM		"sprites/character/back4.xpm"

# define E1_XPM			"sprites/enemy/enemy1"
# define E2_XPM			"sprites/enemy/enemy2"

# define FLOOR_XPM		"sprites/assets/gras.xpm"
# define BORDERS_XPM	"sprites/assets/tree.xpm"

# define COLL_XPM		"sprites/assets/collectible.xpm"
# define EXIT_XPM		"sprites/assets/exit.xpm"

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

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_xmp_img
{
	t_image	right;
	t_image	right2;
	t_image	right3;
	t_image	right4;
	t_image	floor;
	t_image	borders;
	t_image	collectible;
	t_image	exit;
}	t_xmp_img;

/* 	game defintion --> stores the important values of the game */
typedef struct s_data
{
	//for image
	void		*mlx;
	char		*wdw;
	//for game
	char		*map_file;
	char		**map;
	t_xmp_img	xmp_img;
	int			rows;
	int			col;
	int			collectibles;
	int			player;
	int			exit;
	int			x;
	int			y;
	int			error_code;
	int			movements;
	int			d;
	char		tile;
}	t_data;

/* 	function definitions */

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* Read the map and parse the map */

// create the map from the file
int		ft_create_map(t_data *game);
// determine the number of rows and columns
int		ft_rows_and_col(int fd, t_data *game);
// if the line can't be read, free the line and close the file descriptor
void	ft_free_close(char *line, int fd);
// malloc the map and fill it with the actual values
int		ft_fill_map(int fd, t_data *game);
// if there are issues creating the map, free the whole map array
void	ft_free(char **arr, int i);

/* initialize mlx, window and the sprites */

// call the other initialize functions and check whether the init worked or not
int		ft_init(t_data *game);
// initialize the mlx pointer + the window pointer
int		ft_init_mlx(t_data *game);
// initialize the sprites
int		ft_init_images(t_data *game);
// converting the images to xpm
t_image	ft_convert_images(t_data *game, char *path);

/* check map */

// checks the map and calls the other functions to execute specific tests
int		ft_map_checker(t_data *game);
// check if all objects are there (i.e. exit, collectibles and player)
void	ft_check_objects(t_data *game);
// check the surroundings, if they are all borders
void	ft_check_surroundings(t_data *game);
// flood fill the map and...
void	ft_check_path(t_data *game, t_data gmc);
// ... check whether all the objects are there and are reachable
void	ft_check_path_helper(t_data *game, t_data gc, int d);

/* Sprites to Screen */

// puts the map to the screen
void	ft_map_to_screen(t_data *game);
// determines which sprite to put to the screen
void	ft_determine_sprite(t_data *game, int x, int y);
// puts the specific sprite image to the screen
void	ft_put_sprite(t_data *game, t_image *sprite, int x, int y);

/* Inputs */

// key hook function to determine actions for key press;
int		ft_key_hook(int keycode, t_data *game);
// moving player and rendering changes; checking winning condition
void	ft_player_move(t_data *game, int dir, int x, int y);

/* UTILS */

// print errors - depending on error that occurred
void	ft_error_code_printer(t_data *game, int n);
// copy the map so it doesn't get overwritten while checking the path
char	**ft_copy_map(t_data *game);

/* Free and end program */

// close the game and free all the resources
void	ft_close_game(t_data *game);
// free the images used for the program
void	ft_free_images(t_data *game);

#endif
