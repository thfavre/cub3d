#include <stdio.h>

#include "mlx.h"
#include "libft.h"
#include "data.h"
#include "game2d.h"

bool	init(t_data *data);
bool	parser(char *filename, t_data *data);

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc != 2)
	{
		write(2, "Please include a [map].cub file\n", 33);
		return (1);
	}
	else if (!init(&data))
	{
		mlx_destroy_image(data.mlx, data.img.img);
		mlx_destroy_window(data.mlx, data.win);
		free(data.mlx);
		return (1);
	}
	else if (!parser(argv[1], &data))
	{
		mlx_destroy_image(data.mlx, data.img.img);
		mlx_destroy_window(data.mlx, data.win);
		free(data.mlx); // TODO to Bastien (on Mac): try to have two player, does it segfault?? If not delete this comment
		return (1);
	}
	init_settings(&data);
	mlx_loop(data.mlx);
	return (0);
}
