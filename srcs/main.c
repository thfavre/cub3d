#include <stdio.h>

#include "mlx.h"
#include "libft.h"
#include "data.h"
#include "2DGame.h"

bool	init(t_data *data);
bool	parser(char *filename, t_data *data);


int	on_close(t_data *data);


int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		write(2, "Please include a [map].cub file\n", 33);
		return (1);
	}
	else if (!init(&data))
	{
		return (1);
	}
	else if (!parser(argv[1], &data))
	{
		mlx_destroy_image(data.mlx, data.img.img);
		mlx_destroy_window(data.mlx, data.win);
		free(data.mlx);

		return (1);
	}
	init_player(&data.game.player, data.map);
	// put the init obstacles in a function (and better ;) )
	data.game.obstacles.number = 0;
	data.game.obstacles.rects = ft_calloc(sizeof(t_rect), 9999);
	int		i;
	int		j;
	i = 0;

	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == '1')
			{
				data.game.obstacles.rects[data.game.obstacles.number] = (t_rect){j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE};
				data.game.obstacles.number++;
			}
			j++;
		}
		i++;
	}

	// START!!!
	mlx_loop(data.mlx);





	return (0);
}
