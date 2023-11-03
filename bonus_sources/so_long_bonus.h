/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:10:38 by tbenz             #+#    #+#             */
/*   Updated: 2023/11/03 13:16:20 by tbenz            ###   ########.fr       */
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
# define ARGC_ERR	"Error\nSomething went wrong with your input\n"

/* Winning messages */
# define WIN_MESS	"You win! Well done!\n"
# define LO_MESS	"You got lost on the way! Try to escape directly!\n"
# define LO_MESS2	"This is not Pokemon.\nYou don't have to catch them all.\n"

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

# define E1_XPM			"sprites/enemy/enemy1.xpm"
# define E2_XPM			"sprites/enemy/enemy2.xpm"

# define FLOOR_XPM		"sprites/assets/gras.xpm"
# define BORDERS_XPM	"sprites/assets/tree.xpm"

# define COLL_XPM		"sprites/assets/collectible.xpm"
# define EXIT_XPM		"sprites/assets/exit.xpm"

# define FRAME_ENEM		2
# define FRAME_NUM		4
# define FRAME_INTERVAL 200000

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

typedef struct s_enemy
{
	int				x;
	int				y;
	int				frame;
	struct s_enemy	*ptr;
}	t_enemy;

typedef struct s_img_arr
{
	t_image	a[FRAME_NUM];
}	t_char_arr;

typedef struct s_enem_arr
{
	t_image	a[FRAME_ENEM];
}	t_enem_arr;

typedef struct s_xmp_img
{
	t_char_arr	r;
	t_char_arr	l;
	t_char_arr	f;
	t_char_arr	b;
	t_enem_arr	e;
	t_image		floor;
	t_image		borders;
	t_image		collectible;
	t_image		exit;
}	t_xmp_img;

/* 	game defintion --> stores the important values of the game */
typedef struct s_data
{
	void		*mlx;
	char		*wdw;
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
	int			curr_frame;
	int			enem_frame;
	int			sp;
	int			enemy_num;
	t_enemy		*enemy;
	char		tile;
}	t_data;

typedef struct s_bfs
{
	int				x;
	int				y;
	int				dist;
	struct s_bfs	*ptr;
}	t_bfs;

/* 	function definitions */

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* Read the map and parse the map */

// create the map from the file
int		ft_create_map(t_data *game);
// determine the number of rows and columns
int		ft_rows_and_col(int fd, t_data *game);
// if the line can't be read, free the line and close the file descriptor
int		ft_free_close(char *line, int fd, t_data *game, int error_code);
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
void	ft_init_player(t_data *game);
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
// puts the player to the screen, depending on the direction he walks to
void	ft_put_player(t_data *game, int x, int y);
// puts the enemies to the screen
void	ft_put_enemy(t_data *game, int x, int y);
// print the movements on the screen
void	ft_print_movements(t_data *game);

/* Inputs */

// key hook function to determine actions for key press;
int		ft_key_hook(int keycode, t_data *game);
// moving player and rendering changes; checking winning condition
void	ft_player_move(t_data *game, int dir, int x, int y);
// stores the value of the tile the player steps on
void	ft_set_tiles_stats(t_data *game, int x, int y);

/* UTILS */

// print errors - depending on error that occurred
void	ft_error_code_printer(t_data *game, int n);
// copy the map so it doesn't get overwritten while checking the path
char	**ft_copy_map(t_data *game);
// initializes the variables
void	ft_initialize_game(t_data *game);
// puts the specific sprite image to the screen
void	ft_put_sprite(t_data *game, t_image *sprite, int x, int y);
// creates a new enemy, initializes it and adds it to the end of the array
void	ft_create_new_enemy(t_data *game, int x, int y);

/* Utils 2 */
// free the enemy array
void	ft_free_enemy(t_data *game);

/* Free and end program */

// determine if the player went to exit directly; print message
void	ft_win_loose(t_data *game, int mov_to_end, int movto);
// close the game and free all the resources
int		ft_close_game(t_data *game);
// pass all the images that should have been used to the free function
void	ft_images_to_free(t_data *game);
// determines if a images had been assigned and if so, frees it
void	ft_free_images(t_data *game, void *xpm_ptr);

/* Shortest Path to exit after collecting all collectibles */

// determine the shortest path to the exit
void	ft_shortest_path(t_data *game);
// navigates the map and appends new coordinates to a linked list
void	ft_nav_map(t_data *game, t_bfs **lst);
// checks whether a new coordinate should be added to the back of the list
int		ft_corrval(t_data *game, t_bfs **lst, int x, int y);

/* BFS Helpers */

// creates a new bfs list element and initiates the first node element
t_bfs	*ft_lstnew_bfs(t_data *game);
// appends elements to the linked list
void	ft_list_append(t_bfs **lst, int dist, int x, int y);
// pops nodes out of the list and frees their memory space
void	ft_node_pop(t_bfs **lst);
// gets the last element of a linked list and returns it
t_bfs	*ft_lstlast_bfs(t_bfs *lst);
// initites a node, setting the x, y, dist and ptr values
void	ft_node_init(t_bfs **node, int x, int y, int dist);

/* Animation */

// calls the animation functions
int		ft_animation(t_data *game);
// animate the player (cycle through images with offset)
void	ft_animate_player(t_data *game, int frame_ival);
// animate the enemy (cycle through images with offset)
void	ft_animate_enemy(t_data *game, int frame_ival);
// defines the time between animation intervals, depending on # of enemies
int		ft_define_frame_ival(t_data *game);

#endif
