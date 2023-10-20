#include "so_long.h"

void	ft_initialize_game(t_data *game)
{
	game->map_file = "\n";
	game->rows = 0;
	game->col = 0;
	game->collectibles = 0;
	game->exit = 0;
	game->player = 0;
	game->x = 0;
	game->y = 0;
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
	printf("%s\n", game.map_file);
	check = ft_create_map(&game);
	printf("size of map: %lu\n", sizeof(game.map));
	printf("col: %d\t rows: %d\t check: %d\n", game.col, game.rows, check);
	while (i < game.rows)
	{
		printf("%s\n", game.map[i]);
		i++;
	}
	ft_map_checker(&game);
	i = 0;
	while (i < game.rows)
	{
		printf("%s\n", game.map[i]);
		i++;
	}
	printf("%d", game.error_code);
}
