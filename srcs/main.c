#include <stdio.h>

#include "mlx.h"
#include "libft.h"
#include "data.h"
#include "game2d.h"

// map
// BLOCKSIZE = 40;
// map = {
// 	{1, 1, 0, 1, 1},
// 	{1, 0, 0, 1, 1},
// 	{1, 0, 0, 1, 1},
// 	{1, 1, 0, 5, 1}
// }
// -> liste de wall

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
	init_settings(&data);
	// START!!!
	mlx_loop(data.mlx);





	return (0);
}
