#include <stdio.h>

#include "libft.h"
#include "data.h"

// map
// BLOCKSIZE = 40;
// map = {
// 	{1, 1, 0, 1, 1},
// 	{1, 0, 0, 1, 1},
// 	{1, 0, 0, 1, 1},
// 	{1, 1, 0, 5, 1}
// }
// -> liste de wall

bool	init(t_data data);
bool	parser(char *filename, t_data *data);




int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		write(2, "Please include a [map].cub file\n", 33);
		return (1);
	}
	else if (!parser(argv[1], &data))
	{
		return (1);
	}
	else if (!init(data))
	{
		write(2, "Error\n", 6);
		return (1);
	}


	return (0);
}
