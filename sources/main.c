#include "so_long.h"

void	ft_initialize_game(t_data *game)
{
	game->map_file = "\n";
	game->rows = 0;
	game->columns = 0;
	game->collectibles = 0;
	game->exit = 0;
	game->player = 0;
	game->x_pos = 0;
	game->y_pos = 0;
	game->error_code = 0;
}

#include <stdio.h>
int	main(void)
{
	t_data	game;
	int		check;
	int		i = 0;

	ft_initialize_game(&game);
	game.map_file = "../map/map.txt";
	printf("%s", game.map_file);
	check = ft_create_map(&game);
	printf("columns: %d\t rows: %d\t check: %d\n", game.columns, game.rows, check);
	while (i < game.rows)
	{
		printf("%s\n", game.map[i]);
		i++;
	}
	ft_map_checker(&game);
}
